# Exercícios

## Exemplos

1. Aplicação padrão (montador Atmel Studio)

```assembly
.cseg
.org        0x0000

; vetor de IRQ
rjmp reset  ;Reset
nop

;==============================================
; Inicializacao
;==============================================
reset:
    ; inicializa a pilha no endereço final do RAM
    ldi r16, low (RAMEND)
    out spl, r16
    ldi r16, high (RAMEND)

    out sph, R16
    call main
halt:
    jmp halt

;==============================================
; Funcao main
;==============================================
main:
    ;salva registradores utilizados na pilha
    ;opcional para o main
    push r16
    push r17
    push yl
    push yh

    ;passagem de parâmetro por registrador
    ldi r16, 4
    ldi r17, 1
    call soma_16

    ;passagem de parâmtro por pilha
    ;carrega valor do Stack Pointer
    in yl, spl
    in yh, sph
    sbiw yh:yl,7  ;posicina no retorno

    ld r1, y     ;carrega retorno alto 
                ;(topo no ret de soma_16)
    ldd r0, y+1  ;carrega retorno baixo

    ldi yl, low(table)
    ldi yh, high(table)
    ldi r16, 10
    ldi r17, 45
    call init

    main_loop:
        ; Corpo do main
        ; (...)
        jmp main_loop

    ;restaura registradores
    ;opcional para main
    pop yh
    pop yl
    pop r17
    pop r16
    ret
```

2. Criação de funções (montador Atmel Studio).

```assembly
;==============================================
; Funcao init (*vetor, tam, x)
;        init (y     , r16, r17)
;
; parâmetros: y, r16, r17 
; saída: mem[y] até mem [y+r16] recebe r17
;==============================================
init:
    push yl
    push yh
    push r16
    push r17

loop:
    cpi r16, 0
    breq end_i
    st y, r17
    adiw yh:yl, 1
    dec r16
    jmp loop

end_i:
    pop r17
    pop r16
    pop yh
    pop yl
    ret
```

## Execícios

1. Comentar cada linha de instrução dos exemplos anteriores

2. Implementar as seguintes funções em Assembly:
  
    - init(byte *ptr, byte val, byte size): Inicializa uma região de memória
  
    - strlen(byte *ptr);  Retorna o tamanho da string;

    - int strfind(byte car, byte *ptr);  Retorna a posição do caractere encontrado, ou 0xFF se não encontrado
  
    - Pesquise como implementar rotinas de atraso em Assembly.
  
    - Tabelas em memória FLASH podem ser inicializadas por:
        - Rotina Initialize\_RAM deve ser chamada antes do main.

```assembly
StringRamInit:
; This table contains the initial value that should always be
; used for the coefficient table on start-up.  The RAM copy
; of the table will be initialized based on this table.
.equ STRING_SIZE = 14
.db "Hello, world", '\n', 0

Initialize_RAM:
   ; Copy the initial values for the coefficient table from Flash into RAM.
   ldi ZH, high(StringRamInit << 1)
   ldi ZL, low(StringRamInit << 1)
   ldi XH, high(myRAMstring)
   ldi XL, low(myRAMstring)
   ldi r16, STRING_SIZE
Initialize_RAM_Loop:
   lpm r17, Z+
   st X+, r17
   dec r16
   brne Initialize_RAM_Loop
   ret

;Região de dados em RAM
.dseg
.org        0x100
var1:       .BYTE ;   ; reserve 1 byte to var1 
myRAMstring: .BYTE 64 ; reserve 64 bytes
```
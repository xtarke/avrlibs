.cseg 
.org        0x0000

; vetor de IRQ
rjmp reset		;Reset
nop				;

;==============================================
; Inicializacao
;==============================================
reset:
	; inicializa a pilha no endereço final do RAM
	ldi r16, low ( RAMEND )
	out spl, r16
	ldi r16, high (RAMEND )
		
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
	
		;passagem de parâmtro por registrador
	ldi r16, 4
	ldi r17, 1
	call soma_16

	;passagem de parâmtro por pilha
	;carrega valor do Stack Pointer
	in yl, spl
	in yh, sph
	sbiw yh:yl,7   ;posicina no retorno

	ld r1, y     ;carrega retorno alto (topo no ret 
                     ;de soma_16)
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

#include <avr/io.h>

; .device ATMEGA328P
; .include "m328pdef.inc"	// Carrega definicoes do atmega 328


; Este arquivo deve ser sempre com extensão .S (maiúsculo)
; Colocar -nostartfiles como parâmetro do linker
; Criar projeto no eclipse como "Projeto C"


;Inicio do segmento de código
.section .text  ;.cseg (para AVR Studio)
.global     main
.org        0x0000

main:
    ldi	yl, lo8(vector_data)
	ldi	yh, hi8(vector_data)
    ldi r16, 16
    ldi r18, 0
    
    call sum

main_loop:

	; Acesso a registradores de  E/S
	cbi _SFR_IO_ADDR(PORTB), 0

    jmp main_loop



sum:
	push yl
	push yh
	push r16
	push r17

	ldi r18, 0
loop:
	cpi r16, 0
	breq end_i
	ld r17,y
	adiw y, 1
	add r18, r17
	dec r16
	jmp loop

end_i:	
	pop r17
	pop r16
	pop yh
	pop yl
	ret 


.section .data ;.dseg
.org        0x0400
vector_data:.BYTE 16

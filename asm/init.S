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

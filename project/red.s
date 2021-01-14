	.arch msp430g2553
	.balign 2
	.data

dimState:
	.byte 0			;set to 0

jt:				;jump table
	.word case0		;state 0
	.word case1		;state 1
	
	
	.text
	.extern red_on
	.extern led_update

	.global dim50

dim50:
	cmp #1, &dimState 	; comparison
	jc end
	mov.b &dimState, r12 	;set r12 to dimState
	add r12, r12 		;multplying r12
	mov jt(r12), r0 	;move 0 - 1 into r0

case0:
	mov #1, &red_on 	;1 means red led is on
	mov.b #1, &dimState 	;dimState = 1
	jmp end			;goto end

case1:
	mov #0, red_on	 	;0 means red led is off
	mov.b #0, &dimState 	;dimState is set to 0
	jmp end			;goto end

end:
	call #led_update 	;updating the value of led_update
	pop r0

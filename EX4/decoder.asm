.cpu cortex-m0 
.bss
	channel: .fill 0x28
.text 
.align 2 
.global decoder

decoder:
	push {lr} 					@; push the linkerpointer
	ldr	r3, =channel			@; place channel in r3
	ldr	r4, =compressed			@; place pointer to r4
	mov	r5, #0					@; index register
	mov	r6, #0					@; offset register
	mov	r7, #0					@; length register
	
FileLoop:
	ldrb r0, [r4, r5]			@; put char index in r0
	add r5, #1					@; index++
	cmp r0, #0					@; end subroutine when EOF is reached
	beq	done					@; branch to done when r0 == EOF
	
	cmp r0, #'@'				@; check if r0 equals compress token
	beq	decompress				@; branch to decompress
	bl buffer					@; buffering the channel
	bl uart_put_char			@; print the char in r0
	b FileLoop					@; branch back to the fileloop
	
decompress:
	ldrb r6, [r4, r5]			@; load offset into r6
	add r5, #1					@; index++
	ldrb r7, [r4, r5]			@; load lenght into r7
	add r5, #1					@; index++
	sub r6, r6, #'0'			@; -48, make offset char to int
	sub r7, r7, #'0'			@; -48, make lenght char to int
	
decompressLoop:
	ldrb r0, [r3, r6]			@; load memory into r0
	bl buffer					@; branch to buffer subroutine
	bl uart_put_char			@; print char
	sub	r7, #1					@; length--
	beq FileLoop				@; check r7 == 1 if true compression of this part is finished
	b decompressLoop			@; loop
	
buffer:
	push {lr}					@; push the linkerpointer
	mov r1, #39					@; set buffer length in r1

bufferLoop:
	sub r1, #1 					@; index--
	ldrb r2, [r3, r1] 			@; load memory into r2
	add r1, #1					@; index++
	strb r2, [r3, r1]			@; store char in r3 with index r1 into r2
	sub r1, #1					@; index--

	cmp r1, #0					@; compare r1 with 0
	beq bufferDone				@; branch if equal
	b bufferLoop				@; loop
	
bufferDone:
	strb r0, [r3, #0]			@; load char
	pop {pc}					@; pop the programpointer
	
done:
	pop {pc} 					@; pop the programpointer
.global print_asciz
.cpu cortex-m0
.text
.align 1

print_asciz:
    push { r4, lr }
    mov r4, r0

loop:
    ldrb r0, [ r4 ]
    cmp r0, #0
    beq done
    bl convert_char
    bl uart_put_char
    add r4, r4, #1
    b loop

done:
    pop { pc, r4 }


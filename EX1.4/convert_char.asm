.global convert_char
.cpu cortex-m0
.text
.align 1

convert_char:
    push { lr }
    cmp r0, #'Z'
    ble makelower
    cmp r0, #'a'
    bge makehigher
    b done

makelower:
    cmp r0, #'A'
    blt done
    add r0, r0, #'z' - 'Z'
    b done

makehigher:
    cmp r0, #'z'
    bgt done
    sub r0, r0, #'z' - 'Z'

done:
    pop { pc }

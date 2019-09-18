.global application
.cpu cortex-m0

string:
    .asciz "Hello world"

application:
    ldr r0, =string
    bl print_asciz
.global _icontext_get

_icontext_get:

    ; alignment?

    sub     sp, sp, #16
    str     x0, [sp, #8]

    ; save return address

    ldr     x8, [sp, #8]
    str     lr, [x8]

    ; save stack pointer

    mov     x1, sp
    str     x1, [x8, #8]

    ; x19-x28 are callee-saved registers
    ; save them

    str     x19, [x8, #16]
    str     x20, [x8, #24]
    str     x21, [x8, #32]
    str     x22, [x8, #40]
    str     x23, [x8, #48]
    str     x24, [x8, #56]
    str     x25, [x8, #64]
    str     x26, [x8, #72]
    str     x27, [x8, #80]
    str     x28, [x8, #88]

    ; undo alignment?

    add     sp, sp, #16

    ret
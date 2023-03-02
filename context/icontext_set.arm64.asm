.global _icontext_set

_icontext_set:

    ; alignment?

    sub     sp, sp, #16
    str     x0, [sp, #8]

    ; load return address

    ldr     x8, [sp, #8]
    ldr     lr, [x8]

    ; save stack pointer

    ldr     x1, [x8, #8]
    mov     sp, x1

    ; x19-x28 are callee-saved registers
    ; save them

    ldr     x19, [x8, #16]
    ldr     x20, [x8, #24]
    ldr     x21, [x8, #32]
    ldr     x22, [x8, #40]
    ldr     x23, [x8, #48]
    ldr     x24, [x8, #56]
    ldr     x25, [x8, #64]
    ldr     x26, [x8, #72]
    ldr     x27, [x8, #80]
    ldr     x28, [x8, #88]

    ; undo alignment?

    add     sp, sp, #16

    ret
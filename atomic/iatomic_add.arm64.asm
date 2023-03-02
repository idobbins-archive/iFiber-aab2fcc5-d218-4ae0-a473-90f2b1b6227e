.global _iatomic_add

_iatomic_add:

        sub     sp, sp, #16
        str     x0, [sp, #8]
        str     w1, [sp, #4]

        ldr     x8, [sp, #8]
        ldr     w9, [sp, #4]

        ldar     w8, [x8]
        add     w8, w8, w9
        ldr     x9, [sp, #8]
        stlr     w8, [x9]

        add     sp, sp, #16
        ret
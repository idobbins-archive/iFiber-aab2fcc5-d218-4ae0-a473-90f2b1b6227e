.global _iatomic_increment

_iatomic_increment:

        sub     sp, sp, #16
        str     x0, [sp, #8]

        ldr     x8, [sp, #8]

        ldr     x8, [sp, #8]
        ldar    w8, [x8]
        add     w8, w8, #1
        ldr     x9, [sp, #8]
        stlr    w8, [x9]

        add     sp, sp, #16
        ret
.global _iatomic_equal

_iatomic_equal:

        sub     sp, sp, #16
        str     x0, [sp, #8]
        str     w1, [sp, #4]

        ldr     x8, [sp, #8]
        ldr     w9, [sp, #4]

        ldar     w8, [x8]
        subs    w8, w8, w9
        cset    w8, eq
        and     w0, w8, #0x1

        add     sp, sp, #16
        ret
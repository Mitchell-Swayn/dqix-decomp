// Compiler runtime support: _f_ulltof, _ll_uto_f.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_lltof.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_lltof.s.
// DQIX USA arm9/main: 0x0200C76C, 104 bytes.
// Original bytes SHA256: 40ddde464813d60e5086870d8334356a852d4ad7670eba2a44ac006bfdbf1028.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _ll_uto_f()
{

rt_0200c76c:
    cmp r1, #0
rt_0200c770:
    bne rt_0200c77c
rt_0200c774:
    movs r0, r0
rt_0200c778:
    dcd RUNTIME_BRANCH(14, -188) // Shared runtime tail target: _ffltu + 4
rt_0200c77c:
    mov r3, #0x20
rt_0200c780:
    bmi rt_0200c79c
rt_0200c784:
    clz r12, r1
rt_0200c788:
    movs r1, r1, lsl r12
rt_0200c78c:
    sub r3, r3, r12
rt_0200c790:
    orr r1, r1, r0, lsr r3
rt_0200c794:
    rsb r2, r3, #0x20
rt_0200c798:
    mov r0, r0, lsl r2
rt_0200c79c:
    cmp r0, #0
rt_0200c7a0:
    orrne r1, r1, #1
rt_0200c7a4:
    add r3, r3, #0x9e
rt_0200c7a8:
    ands r2, r1, #0xff
rt_0200c7ac:
    add r0, r1, r1
rt_0200c7b0:
    mov r0, r0, lsr #9
rt_0200c7b4:
    orr r0, r0, r3, lsl #23
rt_0200c7b8:
    bxeq lr
rt_0200c7bc:
    tst r2, #0x80
rt_0200c7c0:
    bxeq lr
rt_0200c7c4:
    ands r1, r2, #0x7f
rt_0200c7c8:
    andeqs r1, r0, #1
rt_0200c7cc:
    addne r0, r0, #1
rt_0200c7d0:
    bx lr
}

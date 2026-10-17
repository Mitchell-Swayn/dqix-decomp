// Compiler runtime support: _f_lltof, _ll_sto_f.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_lltof.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_lltof.s.
// DQIX USA arm9/main: 0x0200C700, 108 bytes.
// Original bytes SHA256: 3fdbaf51ae4b33f6390b1e1785054f9cf4ed053adcb5b71f2fa7047db3613863.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _ll_sto_f()
{

rt_0200c700:
    ands r2, r1, #0x80000000
rt_0200c704:
    beq rt_0200c710
rt_0200c708:
    rsbs r0, r0, #0
rt_0200c70c:
    rsc r1, r1, #0
rt_0200c710:
    cmp r1, #0
rt_0200c714:
    bne rt_0200c720
rt_0200c718:
    movs r0, r0
rt_0200c71c:
    dcd RUNTIME_BRANCH(14, -160) // Shared runtime tail target: _fflt + 12
rt_0200c720:
    clz r3, r1
rt_0200c724:
    movs r1, r1, lsl r3
rt_0200c728:
    rsb r3, r3, #0x20
rt_0200c72c:
    orr r1, r1, r0, lsr r3
rt_0200c730:
    rsb r12, r3, #0x20
rt_0200c734:
    movs r0, r0, lsl r12
rt_0200c738:
    orrne r1, r1, #1
rt_0200c73c:
    add r3, r3, #0x9e
rt_0200c740:
    ands r12, r1, #0xff
rt_0200c744:
    add r0, r1, r1
rt_0200c748:
    orr r0, r2, r0, lsr #9
rt_0200c74c:
    orr r0, r0, r3, lsl #23
rt_0200c750:
    bxeq lr
rt_0200c754:
    tst r12, #0x80
rt_0200c758:
    bxeq lr
rt_0200c75c:
    ands r3, r12, #0x7f
rt_0200c760:
    andeqs r3, r0, #1
rt_0200c764:
    addne r0, r0, #1
rt_0200c768:
    bx lr
}

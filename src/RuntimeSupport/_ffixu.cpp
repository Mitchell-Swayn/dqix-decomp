// Compiler runtime support: _f_ftou, _ffixu.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_ftou.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_ftou.s.
// DQIX USA arm9/main: 0x0200C630, 64 bytes.
// Original bytes SHA256: bca10f90b1a31d2b3ff9aab49f848e3c98c2e0a2f6df92a6b62e56ebe8c3c7dd.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ffixu()
{

rt_0200c630:
    tst r0, #0x80000000
rt_0200c634:
    bne rt_0200c654
rt_0200c638:
    mov r1, #0x9e
rt_0200c63c:
    subs r1, r1, r0, lsr #23
rt_0200c640:
    blt rt_0200c668
rt_0200c644:
    mov r2, r0, lsl #8
rt_0200c648:
    orr r0, r2, #0x80000000
rt_0200c64c:
    mov r0, r0, lsr r1
rt_0200c650:
    bx lr
rt_0200c654:
    mov r2, #0xff000000
rt_0200c658:
    cmp r2, r0, lsl #1
rt_0200c65c:
    movhs r0, #0
rt_0200c660:
    mvnlo r0, #0
rt_0200c664:
    bx lr
rt_0200c668:
    mvn r0, #0
rt_0200c66c:
    bx lr
}

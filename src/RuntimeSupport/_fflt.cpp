// Compiler runtime support: _f_itof, _fflt.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_itof.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_itof.s.
// DQIX USA arm9/main: 0x0200C670, 72 bytes.
// Original bytes SHA256: 23ede7780499aa4d14fc532deb5e0ea7b35ee3b155dc70327368c88037330563.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fflt()
{

rt_0200c670:
    ands r2, r0, #0x80000000
rt_0200c674:
    rsbmi r0, r0, #0
rt_0200c678:
    cmp r0, #0
rt_0200c67c:
    bxeq lr
rt_0200c680:
    clz r3, r0
rt_0200c684:
    movs r0, r0, lsl r3
rt_0200c688:
    rsb r3, r3, #0x9e
rt_0200c68c:
    ands r1, r0, #0xff
rt_0200c690:
    add r0, r0, r0
rt_0200c694:
    orr r0, r2, r0, lsr #9
rt_0200c698:
    orr r0, r0, r3, lsl #23
rt_0200c69c:
    bxeq lr
rt_0200c6a0:
    tst r1, #0x80
rt_0200c6a4:
    bxeq lr
rt_0200c6a8:
    ands r3, r1, #0x7f
rt_0200c6ac:
    andeqs r3, r0, #1
rt_0200c6b0:
    addne r0, r0, #1
rt_0200c6b4:
    bx lr
}

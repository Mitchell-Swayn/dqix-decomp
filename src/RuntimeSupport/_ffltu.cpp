// Compiler runtime support: _f_utof, _ffltu.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_itof.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_itof.s.
// DQIX USA arm9/main: 0x0200C6B8, 72 bytes.
// Original bytes SHA256: 770a6347a450031c316f34fcb22fcf452a2bd1a0f2fcd1abb3b7b70f146dd8ba.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ffltu()
{

rt_0200c6b8:
    cmp r0, #0
rt_0200c6bc:
    bxeq lr
rt_0200c6c0:
    mov r3, #0x9e
rt_0200c6c4:
    bmi rt_0200c6d4
rt_0200c6c8:
    clz r12, r0
rt_0200c6cc:
    movs r0, r0, lsl r12
rt_0200c6d0:
    sub r3, r3, r12
rt_0200c6d4:
    ands r2, r0, #0xff
rt_0200c6d8:
    add r0, r0, r0
rt_0200c6dc:
    mov r0, r0, lsr #9
rt_0200c6e0:
    orr r0, r0, r3, lsl #23
rt_0200c6e4:
    bxeq lr
rt_0200c6e8:
    tst r2, #0x80
rt_0200c6ec:
    bxeq lr
rt_0200c6f0:
    ands r1, r2, #0x7f
rt_0200c6f4:
    andeqs r1, r0, #1
rt_0200c6f8:
    addne r0, r0, #1
rt_0200c6fc:
    bx lr
}

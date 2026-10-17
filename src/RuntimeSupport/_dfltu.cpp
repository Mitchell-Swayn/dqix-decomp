// Compiler runtime support: _d_utod, _dfltu.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_itod.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_itod.s.
// DQIX USA arm9/main: 0x0200B0B4, 60 bytes.
// Original bytes SHA256: 3859ba8fff3004ff81ea2ce721d63ef25ac866b11195e2526af9971b6fa4e472.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dfltu()
{

rt_0200b0b4:
    cmp r0, #0
rt_0200b0b8:
    mov r1, #0
rt_0200b0bc:
    bxeq lr
rt_0200b0c0:
    mov r3, #0x400
rt_0200b0c4:
    add r3, r3, #0x1e
rt_0200b0c8:
    bmi rt_0200b0d8
rt_0200b0cc:
    clz r12, r0
rt_0200b0d0:
    movs r0, r0, lsl r12
rt_0200b0d4:
    sub r3, r3, r12
rt_0200b0d8:
    mov r1, r0
rt_0200b0dc:
    mov r0, r1, lsl #0x15
rt_0200b0e0:
    add r1, r1, r1
rt_0200b0e4:
    mov r1, r1, lsr #0xc
rt_0200b0e8:
    orr r1, r1, r3, lsl #20
rt_0200b0ec:
    bx lr
}

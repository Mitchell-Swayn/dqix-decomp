// Compiler runtime support: _d_itod, _dflt.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_itod.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_itod.s.
// DQIX USA arm9/main: 0x0200B074, 64 bytes.
// Original bytes SHA256: 7478e16a269a5835b5258a7df8529b2bf9021a7106421a7ae9623a01b9ac4a4a.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dflt()
{

rt_0200b074:
    ands r2, r0, #0x80000000
rt_0200b078:
    rsbmi r0, r0, #0
rt_0200b07c:
    cmp r0, #0
rt_0200b080:
    mov r1, #0
rt_0200b084:
    bxeq lr
rt_0200b088:
    mov r3, #0x400
rt_0200b08c:
    add r3, r3, #0x1e
rt_0200b090:
    clz r12, r0
rt_0200b094:
    movs r0, r0, lsl r12
rt_0200b098:
    sub r3, r3, r12
rt_0200b09c:
    movs r1, r0
rt_0200b0a0:
    mov r0, r1, lsl #0x15
rt_0200b0a4:
    add r1, r1, r1
rt_0200b0a8:
    orr r1, r2, r1, lsr #12
rt_0200b0ac:
    orr r1, r1, r3, lsl #20
rt_0200b0b0:
    bx lr
}

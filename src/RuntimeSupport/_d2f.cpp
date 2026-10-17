// Compiler runtime support: _f_qtof, _d_dtof, _d2f.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_dtof.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_dtof.s.
// DQIX USA arm9/main: 0x0200AE40, 260 bytes.
// Original bytes SHA256: 46d1b63c88842e40fffdc01550cd8902742a3ced15bb4c22b9cc8cf0ebf7d459.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _d2f()
{

rt_0200ae40:
    and r2, r1, #0x80000000
rt_0200ae44:
    mov r12, r1, lsr #0x14
rt_0200ae48:
    bics r12, r12, #0x800
rt_0200ae4c:
    beq rt_0200aeb8
rt_0200ae50:
    mov r3, r12, lsl #0x15
rt_0200ae54:
    cmn r3, #0x200000
rt_0200ae58:
    bhs rt_0200ae9c
rt_0200ae5c:
    subs r12, r12, #0x380
rt_0200ae60:
    bls rt_0200aec8
rt_0200ae64:
    cmp r12, #0xff
rt_0200ae68:
    bge rt_0200af38
rt_0200ae6c:
    mov r1, r1, lsl #0xc
rt_0200ae70:
    orr r3, r2, r1, lsr #9
rt_0200ae74:
    orr r3, r3, r0, lsr #29
rt_0200ae78:
    movs r1, r0, lsl #3
rt_0200ae7c:
    orr r0, r3, r12, lsl #23
rt_0200ae80:
    bxeq lr
rt_0200ae84:
    tst r1, #0x80000000
rt_0200ae88:
    bxeq lr
rt_0200ae8c:
    movs r1, r1, lsl #1
rt_0200ae90:
    andeqs r1, r0, #1
rt_0200ae94:
    addne r0, r0, #1
rt_0200ae98:
    bx lr
rt_0200ae9c:
    orrs r3, r0, r1, lsl #12
rt_0200aea0:
    bne rt_0200aeb0
rt_0200aea4:
    mov r0, #0xff000000
rt_0200aea8:
    orr r0, r2, r0, lsr #1
rt_0200aeac:
    bx lr
rt_0200aeb0:
    mvn r0, #0x80000000
rt_0200aeb4:
    bx lr
rt_0200aeb8:
    orrs r3, r0, r1, lsl #12
rt_0200aebc:
    bne rt_0200af30
rt_0200aec0:
    mov r0, r2
rt_0200aec4:
    bx lr
rt_0200aec8:
    cmn r12, #0x17
rt_0200aecc:
    beq rt_0200af1c
rt_0200aed0:
    bmi rt_0200af30
rt_0200aed4:
    mov r1, r1, lsl #0xb
rt_0200aed8:
    orr r1, r1, #0x80000000
rt_0200aedc:
    mov r3, r1, lsr #8
rt_0200aee0:
    orr r3, r3, r0, lsr #29
rt_0200aee4:
    rsb r12, r12, #1
rt_0200aee8:
    movs r1, r0, lsl #3
rt_0200aeec:
    orr r0, r2, r3, lsr r12
rt_0200aef0:
    rsb r12, r12, #0x20
rt_0200aef4:
    mov r3, r3, lsl r12
rt_0200aef8:
    orrne r3, r3, #1
rt_0200aefc:
    movs r1, r3
rt_0200af00:
    bxeq lr
rt_0200af04:
    tst r1, #0x80000000
rt_0200af08:
    bxeq lr
rt_0200af0c:
    movs r1, r1, lsl #1
rt_0200af10:
    andeqs r1, r0, #1
rt_0200af14:
    addne r0, r0, #1
rt_0200af18:
    bx lr
rt_0200af1c:
    orr r0, r0, r1, lsl #12
rt_0200af20:
    movs r1, r0
rt_0200af24:
    mov r0, r2
rt_0200af28:
    addne r0, r0, #1
rt_0200af2c:
    bx lr
rt_0200af30:
    mov r0, r2
rt_0200af34:
    bx lr
rt_0200af38:
    mov r0, #0xff000000
rt_0200af3c:
    orr r0, r2, r0, lsr #1
rt_0200af40:
    bx lr
}

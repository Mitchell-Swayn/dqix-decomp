// Compiler runtime support: _d_fne, _dneq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BEDC, 140 bytes.
// Original bytes SHA256: 72c6fbb9b03bd663f0478fd48cd17308e889897d92b307318ec03b004a76b68e.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dneq()
{

rt_0200bedc:
    mov r12, #0x200000
rt_0200bee0:
    cmn r12, r1, lsl #1
rt_0200bee4:
    bhs rt_0200bf44
rt_0200bee8:
    cmn r12, r3, lsl #1
rt_0200beec:
    bhs rt_0200bf58
rt_0200bef0:
    orrs r12, r3, r1
rt_0200bef4:
    bmi rt_0200bf20
rt_0200bef8:
    cmp r1, r3
rt_0200befc:
    cmpeq r0, r2
rt_0200bf00:
    movne r0, #1
rt_0200bf04:
    moveq r0, #0
rt_0200bf08:
    bx lr
rt_0200bf0c:
    mov r0, #1
rt_0200bf10:
    mrs r12, cpsr
rt_0200bf14:
    bic r12, r12, #0x40000000
rt_0200bf18:
    msr cpsr_f, r12
rt_0200bf1c:
    bx lr
rt_0200bf20:
    orr r12, r0, r12, lsl #1
rt_0200bf24:
    orrs r12, r12, r2
rt_0200bf28:
    moveq r0, #0
rt_0200bf2c:
    bxeq lr
rt_0200bf30:
    cmp r3, r1
rt_0200bf34:
    cmpeq r2, r0
rt_0200bf38:
    movne r0, #1
rt_0200bf3c:
    moveq r0, #0
rt_0200bf40:
    bx lr
rt_0200bf44:
    bne rt_0200bf0c
rt_0200bf48:
    cmp r0, #0
rt_0200bf4c:
    bhi rt_0200bf0c
rt_0200bf50:
    cmn r12, r3, lsl #1
rt_0200bf54:
    blo rt_0200bef0
rt_0200bf58:
    bne rt_0200bf0c
rt_0200bf5c:
    cmp r2, #0
rt_0200bf60:
    bhi rt_0200bf0c
rt_0200bf64:
    b rt_0200bef0
}

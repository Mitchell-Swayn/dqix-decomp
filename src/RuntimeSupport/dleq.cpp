// Compiler runtime support: _d_fle, _dleq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BD10, 164 bytes.
// Original bytes SHA256: 0107b9d5fd30718d14dce4f537f3393c3f8ac4d8b4ee4414796e8e35384265a3.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dleq()
{

rt_0200bd10:
    mov r12, #0x200000
rt_0200bd14:
    cmn r12, r1, lsl #1
rt_0200bd18:
    bhs rt_0200bd90
rt_0200bd1c:
    cmn r12, r3, lsl #1
rt_0200bd20:
    bhs rt_0200bda4
rt_0200bd24:
    orrs r12, r3, r1
rt_0200bd28:
    bmi rt_0200bd58
rt_0200bd2c:
    cmp r1, r3
rt_0200bd30:
    cmpeq r0, r2
rt_0200bd34:
    movls r0, #1
rt_0200bd38:
    movhi r0, #0
rt_0200bd3c:
    bx lr
rt_0200bd40:
    mov r0, #0
rt_0200bd44:
    mrs r12, cpsr
rt_0200bd48:
    bic r12, r12, #0x40000000
rt_0200bd4c:
    orr r12, r12, #0x20000000
rt_0200bd50:
    msr cpsr_f, r12
rt_0200bd54:
    bx lr
rt_0200bd58:
    orr r12, r0, r12, lsl #1
rt_0200bd5c:
    orrs r12, r12, r2
rt_0200bd60:
    moveq r0, #1
rt_0200bd64:
    bne rt_0200bd7c
rt_0200bd68:
    mrs r12, cpsr
rt_0200bd6c:
    bic r12, r12, #0x20000000
rt_0200bd70:
    orr r12, r12, #0x40000000
rt_0200bd74:
    msr cpsr_f, r12
rt_0200bd78:
    bxeq lr
rt_0200bd7c:
    cmp r3, r1
rt_0200bd80:
    cmpeq r2, r0
rt_0200bd84:
    movls r0, #1
rt_0200bd88:
    movhi r0, #0
rt_0200bd8c:
    bx lr
rt_0200bd90:
    bne rt_0200bd40
rt_0200bd94:
    cmp r0, #0
rt_0200bd98:
    bhi rt_0200bd40
rt_0200bd9c:
    cmn r12, r3, lsl #1
rt_0200bda0:
    blo rt_0200bd24
rt_0200bda4:
    bne rt_0200bd40
rt_0200bda8:
    cmp r2, #0
rt_0200bdac:
    bhi rt_0200bd40
rt_0200bdb0:
    b rt_0200bd24
}

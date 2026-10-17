// Compiler runtime support: _d_fge, _dgeq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BBE0, 152 bytes.
// Original bytes SHA256: 08138c3c23982b37134dbfa713d5e18a31ec2157471d9309b31054f23883aa9f.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dgeq()
{

rt_0200bbe0:
    mov r12, #0x200000
rt_0200bbe4:
    cmn r12, r1, lsl #1
rt_0200bbe8:
    bhs rt_0200bc54
rt_0200bbec:
    cmn r12, r3, lsl #1
rt_0200bbf0:
    bhs rt_0200bc68
rt_0200bbf4:
    orrs r12, r3, r1
rt_0200bbf8:
    bmi rt_0200bc24
rt_0200bbfc:
    cmp r1, r3
rt_0200bc00:
    cmpeq r0, r2
rt_0200bc04:
    movhs r0, #1
rt_0200bc08:
    movlo r0, #0
rt_0200bc0c:
    bx lr
rt_0200bc10:
    mov r0, #0
rt_0200bc14:
    mrs r12, cpsr
rt_0200bc18:
    bic r12, r12, #0x20000000
rt_0200bc1c:
    msr cpsr_f, r12
rt_0200bc20:
    bx lr
rt_0200bc24:
    orr r12, r0, r12, lsl #1
rt_0200bc28:
    orrs r12, r12, r2
rt_0200bc2c:
    moveq r0, #1
rt_0200bc30:
    mrs r12, cpsr
rt_0200bc34:
    orr r12, r12, #0x20000000
rt_0200bc38:
    msr cpsr_f, r12
rt_0200bc3c:
    bxeq lr
rt_0200bc40:
    cmp r3, r1
rt_0200bc44:
    cmpeq r2, r0
rt_0200bc48:
    movhs r0, #1
rt_0200bc4c:
    movlo r0, #0
rt_0200bc50:
    bx lr
rt_0200bc54:
    bne rt_0200bc10
rt_0200bc58:
    cmp r0, #0
rt_0200bc5c:
    bhi rt_0200bc10
rt_0200bc60:
    cmn r12, r3, lsl #1
rt_0200bc64:
    blo rt_0200bbf4
rt_0200bc68:
    bne rt_0200bc10
rt_0200bc6c:
    cmp r2, #0
rt_0200bc70:
    bhi rt_0200bc10
rt_0200bc74:
    b rt_0200bbf4
}

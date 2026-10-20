// Compiler runtime support: _d_flt, _dls.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BDB4, 156 bytes.
// Original bytes SHA256: c89eab0fdc174faf385a8d90c50be7178a9462fc3664374ac6d2100113b84ebc.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dls()
{

rt_0200bdb4:
    mov r12, #0x200000
rt_0200bdb8:
    cmn r12, r1, lsl #1
rt_0200bdbc:
    bhs rt_0200be2c
rt_0200bdc0:
    cmn r12, r3, lsl #1
rt_0200bdc4:
    bhs rt_0200be40
rt_0200bdc8:
    orrs r12, r3, r1
rt_0200bdcc:
    bmi rt_0200bdf8
rt_0200bdd0:
    cmp r1, r3
rt_0200bdd4:
    cmpeq r0, r2
rt_0200bdd8:
    movlo r0, #1
rt_0200bddc:
    movhs r0, #0
rt_0200bde0:
    bx lr
rt_0200bde4:
    mov r0, #0
rt_0200bde8:
    mrs r12, cpsr
rt_0200bdec:
    orr r12, r12, #0x20000000
rt_0200bdf0:
    msr cpsr_f, r12
rt_0200bdf4:
    bx lr
rt_0200bdf8:
    orr r12, r0, r12, lsl #1
rt_0200bdfc:
    orrs r12, r12, r2
rt_0200be00:
    moveq r0, #0
rt_0200be04:
    bne rt_0200be18
rt_0200be08:
    mrs r12, cpsr
rt_0200be0c:
    orr r12, r12, #0x20000000
rt_0200be10:
    msr cpsr_f, r12
rt_0200be14:
    bxeq lr
rt_0200be18:
    cmp r3, r1
rt_0200be1c:
    cmpeq r2, r0
rt_0200be20:
    movlo r0, #1
rt_0200be24:
    movhs r0, #0
rt_0200be28:
    bx lr
rt_0200be2c:
    bne rt_0200bde4
rt_0200be30:
    cmp r0, #0
rt_0200be34:
    bhi rt_0200bde4
rt_0200be38:
    cmn r12, r3, lsl #1
rt_0200be3c:
    blo rt_0200bdc8
rt_0200be40:
    bne rt_0200bde4
rt_0200be44:
    cmp r2, #0
rt_0200be48:
    bhi rt_0200bde4
rt_0200be4c:
    b rt_0200bdc8
}

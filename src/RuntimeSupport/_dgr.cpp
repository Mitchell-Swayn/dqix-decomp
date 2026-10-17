// Compiler runtime support: _d_fgt, _dgr.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BC78, 152 bytes.
// Original bytes SHA256: ca8000309ac178595c6eb23e7f8c27797667224867a56b90b5ebdf5f4bbae12d.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dgr()
{

rt_0200bc78:
    mov r12, #0x200000
rt_0200bc7c:
    cmn r12, r1, lsl #1
rt_0200bc80:
    bhs rt_0200bcec
rt_0200bc84:
    cmn r12, r3, lsl #1
rt_0200bc88:
    bhs rt_0200bd00
rt_0200bc8c:
    orrs r12, r3, r1
rt_0200bc90:
    bmi rt_0200bcbc
rt_0200bc94:
    cmp r1, r3
rt_0200bc98:
    cmpeq r0, r2
rt_0200bc9c:
    movhi r0, #1
rt_0200bca0:
    movls r0, #0
rt_0200bca4:
    bx lr
rt_0200bca8:
    mov r0, #0
rt_0200bcac:
    mrs r12, cpsr
rt_0200bcb0:
    bic r12, r12, #0x20000000
rt_0200bcb4:
    msr cpsr_f, r12
rt_0200bcb8:
    bx lr
rt_0200bcbc:
    orr r12, r0, r12, lsl #1
rt_0200bcc0:
    orrs r12, r12, r2
rt_0200bcc4:
    moveq r0, #0
rt_0200bcc8:
    mrs r12, cpsr
rt_0200bccc:
    bic r12, r12, #0x20000000
rt_0200bcd0:
    msr cpsr_f, r12
rt_0200bcd4:
    bxeq lr
rt_0200bcd8:
    cmp r3, r1
rt_0200bcdc:
    cmpeq r2, r0
rt_0200bce0:
    movhi r0, #1
rt_0200bce4:
    movls r0, #0
rt_0200bce8:
    bx lr
rt_0200bcec:
    bne rt_0200bca8
rt_0200bcf0:
    cmp r0, #0
rt_0200bcf4:
    bhi rt_0200bca8
rt_0200bcf8:
    cmn r12, r3, lsl #1
rt_0200bcfc:
    blo rt_0200bc8c
rt_0200bd00:
    bne rt_0200bca8
rt_0200bd04:
    cmp r2, #0
rt_0200bd08:
    bhi rt_0200bca8
rt_0200bd0c:
    b rt_0200bc8c
}

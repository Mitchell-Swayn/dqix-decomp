// Compiler runtime support: _f_fgt, _fgr.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BFC4, 92 bytes.
// Original bytes SHA256: 14781c4eadc2af64900cd3236124dc5851c1e0d73aff5ec1592c0ca0036849a2.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fgr()
{

rt_0200bfc4:
    mov r3, #0xff000000
rt_0200bfc8:
    cmp r3, r0, lsl #1
rt_0200bfcc:
    cmphs r3, r1, lsl #1
rt_0200bfd0:
    blo rt_0200c00c
rt_0200bfd4:
    cmp r0, #0
rt_0200bfd8:
    bicmi r0, r0, #0x80000000
rt_0200bfdc:
    rsbmi r0, r0, #0
rt_0200bfe0:
    cmp r1, #0
rt_0200bfe4:
    bicmi r1, r1, #0x80000000
rt_0200bfe8:
    rsbmi r1, r1, #0
rt_0200bfec:
    cmp r0, r1
rt_0200bff0:
    movgt r0, #1
rt_0200bff4:
    movle r0, #0
rt_0200bff8:
    mrs r12, cpsr
rt_0200bffc:
    bicle r12, r12, #0x20000000
rt_0200c000:
    orrgt r12, r12, #0x20000000
rt_0200c004:
    msr cpsr_f, r12
rt_0200c008:
    bx lr
rt_0200c00c:
    mov r0, #0
rt_0200c010:
    mrs r12, cpsr
rt_0200c014:
    bic r12, r12, #0x20000000
rt_0200c018:
    msr cpsr_f, r12
rt_0200c01c:
    bx lr
}

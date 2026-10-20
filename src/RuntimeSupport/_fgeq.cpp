// Compiler runtime support: _f_fge, _fgeq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BF68, 92 bytes.
// Original bytes SHA256: 386719fa984453de893ef70eba0989bb085c318f7ae0adbeac1480436480944a.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fgeq()
{

rt_0200bf68:
    mov r3, #0xff000000
rt_0200bf6c:
    cmp r3, r0, lsl #1
rt_0200bf70:
    cmphs r3, r1, lsl #1
rt_0200bf74:
    blo rt_0200bfb0
rt_0200bf78:
    cmp r0, #0
rt_0200bf7c:
    bicmi r0, r0, #0x80000000
rt_0200bf80:
    rsbmi r0, r0, #0
rt_0200bf84:
    cmp r1, #0
rt_0200bf88:
    bicmi r1, r1, #0x80000000
rt_0200bf8c:
    rsbmi r1, r1, #0
rt_0200bf90:
    cmp r0, r1
rt_0200bf94:
    movge r0, #1
rt_0200bf98:
    movlt r0, #0
rt_0200bf9c:
    mrs r12, cpsr
rt_0200bfa0:
    biclt r12, r12, #0x20000000
rt_0200bfa4:
    orrge r12, r12, #0x20000000
rt_0200bfa8:
    msr cpsr_f, r12
rt_0200bfac:
    bx lr
rt_0200bfb0:
    mov r0, #0
rt_0200bfb4:
    mrs r12, cpsr
rt_0200bfb8:
    bic r12, r12, #0x20000000
rt_0200bfbc:
    msr cpsr_f, r12
rt_0200bfc0:
    bx lr
}

// Compiler runtime support: _f_fle, _fleq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200C020, 104 bytes.
// Original bytes SHA256: 843c40fd75846b9dfc4d506851d6179e2f7b910a6b0fa8b9ed857077ca064e37.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fleq()
{

rt_0200c020:
    mov r3, #0xff000000
rt_0200c024:
    cmp r3, r0, lsl #1
rt_0200c028:
    cmphs r3, r1, lsl #1
rt_0200c02c:
    blo rt_0200c070
rt_0200c030:
    cmp r0, #0
rt_0200c034:
    bicmi r0, r0, #0x80000000
rt_0200c038:
    rsbmi r0, r0, #0
rt_0200c03c:
    cmp r1, #0
rt_0200c040:
    bicmi r1, r1, #0x80000000
rt_0200c044:
    rsbmi r1, r1, #0
rt_0200c048:
    cmp r0, r1
rt_0200c04c:
    movle r0, #1
rt_0200c050:
    movgt r0, #0
rt_0200c054:
    mrs r12, cpsr
rt_0200c058:
    orrgt r12, r12, #0x20000000
rt_0200c05c:
    bicgt r12, r12, #0x40000000
rt_0200c060:
    bicle r12, r12, #0x20000000
rt_0200c064:
    orrle r12, r12, #0x40000000
rt_0200c068:
    msr cpsr_f, r12
rt_0200c06c:
    bx lr
rt_0200c070:
    mov r0, #0
rt_0200c074:
    mrs r12, cpsr
rt_0200c078:
    bic r12, r12, #0x40000000
rt_0200c07c:
    orr r12, r12, #0x20000000
rt_0200c080:
    msr cpsr_f, r12
rt_0200c084:
    bx lr
}

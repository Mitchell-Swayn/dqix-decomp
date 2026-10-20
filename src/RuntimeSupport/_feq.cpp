// Compiler runtime support: _f_feq, _feq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200C0E4, 104 bytes.
// Original bytes SHA256: b8b930efa19ca1d0a51b1f8eb45f326f673e959f4550cec7c5772ee338101c7e.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _feq()
{

rt_0200c0e4:
    mov r3, #0xff000000
rt_0200c0e8:
    cmp r3, r0, lsl #1
rt_0200c0ec:
    blo rt_0200c138
rt_0200c0f0:
    cmp r3, r1, lsl #1
rt_0200c0f4:
    blo rt_0200c138
rt_0200c0f8:
    orr r3, r0, r1
rt_0200c0fc:
    movs r3, r3, lsl #1
rt_0200c100:
    moveq r0, #1
rt_0200c104:
    bne rt_0200c118
rt_0200c108:
    mrs r12, cpsr
rt_0200c10c:
    orr r12, r12, #0x40000000
rt_0200c110:
    msr cpsr_f, r12
rt_0200c114:
    bx lr
rt_0200c118:
    cmp r0, r1
rt_0200c11c:
    moveq r0, #1
rt_0200c120:
    movne r0, #0
rt_0200c124:
    mrs r12, cpsr
rt_0200c128:
    orreq r12, r12, #0x40000000
rt_0200c12c:
    bicne r12, r12, #0x40000000
rt_0200c130:
    msr cpsr_f, r12
rt_0200c134:
    bx lr
rt_0200c138:
    mov r0, #0
rt_0200c13c:
    mrs r12, cpsr
rt_0200c140:
    bic r12, r12, #0x40000000
rt_0200c144:
    msr cpsr_f, r12
rt_0200c148:
    bx lr
}

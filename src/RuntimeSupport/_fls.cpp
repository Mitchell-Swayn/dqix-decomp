// Compiler runtime support: _f_flt, _fls.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200C088, 92 bytes.
// Original bytes SHA256: 999e8951fe0432f49ad3a5549f38a01df9936278ce8082e476c7902ead23cd2f.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fls()
{

rt_0200c088:
    mov r3, #0xff000000
rt_0200c08c:
    cmp r3, r0, lsl #1
rt_0200c090:
    cmphs r3, r1, lsl #1
rt_0200c094:
    blo rt_0200c0d0
rt_0200c098:
    cmp r0, #0
rt_0200c09c:
    bicmi r0, r0, #0x80000000
rt_0200c0a0:
    rsbmi r0, r0, #0
rt_0200c0a4:
    cmp r1, #0
rt_0200c0a8:
    bicmi r1, r1, #0x80000000
rt_0200c0ac:
    rsbmi r1, r1, #0
rt_0200c0b0:
    cmp r0, r1
rt_0200c0b4:
    movlt r0, #1
rt_0200c0b8:
    movge r0, #0
rt_0200c0bc:
    mrs r12, cpsr
rt_0200c0c0:
    orrge r12, r12, #0x20000000
rt_0200c0c4:
    biclt r12, r12, #0x20000000
rt_0200c0c8:
    msr cpsr_f, r12
rt_0200c0cc:
    bx lr
rt_0200c0d0:
    mov r0, #0
rt_0200c0d4:
    mrs r12, cpsr
rt_0200c0d8:
    orr r12, r12, #0x20000000
rt_0200c0dc:
    msr cpsr_f, r12
rt_0200c0e0:
    bx lr
}

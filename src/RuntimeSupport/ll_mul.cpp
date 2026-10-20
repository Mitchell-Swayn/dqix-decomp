// Compiler runtime support: _ull_mul, _ll_mul.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _ll_mul.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_ll_mul.s.
// DQIX USA arm9/main: 0x0200CF24, 32 bytes.
// Original bytes SHA256: 661b48b2adf3a6af3987ca653b5aaa2172d0d5137c91c6658cf18189b776a714.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ll_mul()
{

rt_0200cf24:
    stmdb sp!, {r4, r5, lr}
rt_0200cf28:
    umull r5, r4, r0, r2
rt_0200cf2c:
    mla r4, r0, r3, r4
rt_0200cf30:
    mla r4, r2, r1, r4
rt_0200cf34:
    mov r1, r4
rt_0200cf38:
    mov r0, r5
rt_0200cf3c:
    ldmia sp!, {r4, r5, lr}
rt_0200cf40:
    bx lr
}

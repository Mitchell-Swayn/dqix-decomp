// Compiler runtime support: _f_ftoi, _ffix.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_ftoi.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_ftoi.s.
// DQIX USA arm9/main: 0x0200C5FC, 52 bytes.
// Original bytes SHA256: d5fd0208b26ed20e8eb752c2d96599d06f504fdb31f79713269d19abe2fb9e91.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ffix()
{

rt_0200c5fc:
    bic r1, r0, #0x80000000
rt_0200c600:
    mov r2, #0x9e
rt_0200c604:
    subs r2, r2, r1, lsr #23
rt_0200c608:
    ble rt_0200c624
rt_0200c60c:
    mov r1, r1, lsl #8
rt_0200c610:
    orr r1, r1, #0x80000000
rt_0200c614:
    cmp r0, #0
rt_0200c618:
    mov r0, r1, lsr r2
rt_0200c61c:
    rsbmi r0, r0, #0
rt_0200c620:
    bx lr
rt_0200c624:
    mvn r0, r0, asr #31
rt_0200c628:
    add r0, r0, #0x80000000
rt_0200c62c:
    bx lr
}

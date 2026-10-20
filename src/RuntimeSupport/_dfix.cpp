// Compiler runtime support: _d_dtoi, _dfix.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_dtoi.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_dtoi.s.
// DQIX USA arm9/main: 0x0200AF44, 76 bytes.
// Original bytes SHA256: f391de4cee74649ab1507aed3892b723664fe078e8495b127d167e92a53aa2a0.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dfix()
{

rt_0200af44:
    bic r3, r1, #0x80000000
rt_0200af48:
    ldr r2, [pc, #60] // Literal at 0x0200af8c
rt_0200af4c:
    subs r2, r2, r3, lsr #20
rt_0200af50:
    ble rt_0200af80
rt_0200af54:
    cmp r2, #0x20
rt_0200af58:
    bge rt_0200af78
rt_0200af5c:
    mov r3, r1, lsl #0xb
rt_0200af60:
    orr r3, r3, #0x80000000
rt_0200af64:
    orr r3, r3, r0, lsr #21
rt_0200af68:
    cmp r1, #0
rt_0200af6c:
    mov r0, r3, lsr r2
rt_0200af70:
    rsbmi r0, r0, #0
rt_0200af74:
    bx lr
rt_0200af78:
    mov r0, #0
rt_0200af7c:
    bx lr
rt_0200af80:
    mvn r0, r1, asr #31
rt_0200af84:
    add r0, r0, #0x80000000
rt_0200af88:
    bx lr
rt_0200af8c:
    dcd 0x0000041e // Literal/table data, not an instruction.
}

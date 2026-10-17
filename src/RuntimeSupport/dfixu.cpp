// Compiler runtime support: _d_dtou, _dfixu.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_dtou.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_dtou.s.
// DQIX USA arm9/main: 0x0200AF90, 88 bytes.
// Original bytes SHA256: ec215384d1cf23dc4be407c66ab6909a430d5107b89695fbe7a390c9c65ac078.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dfixu()
{

rt_0200af90:
    tst r1, #0x80000000
rt_0200af94:
    bne rt_0200afc8
rt_0200af98:
    ldr r2, [pc, #68] // Literal at 0x0200afe4
rt_0200af9c:
    subs r2, r2, r1, lsr #20
rt_0200afa0:
    blt rt_0200afdc
rt_0200afa4:
    cmp r2, #0x20
rt_0200afa8:
    bge rt_0200afc0
rt_0200afac:
    mov r3, r1, lsl #0xb
rt_0200afb0:
    orr r3, r3, #0x80000000
rt_0200afb4:
    orr r3, r3, r0, lsr #21
rt_0200afb8:
    mov r0, r3, lsr r2
rt_0200afbc:
    bx lr
rt_0200afc0:
    mov r0, #0
rt_0200afc4:
    bx lr
rt_0200afc8:
    cmn r1, #0x100000
rt_0200afcc:
    cmpeq r0, #0
rt_0200afd0:
    movls r0, #0
rt_0200afd4:
    mvnhi r0, #0
rt_0200afd8:
    bx lr
rt_0200afdc:
    mvn r0, #0
rt_0200afe0:
    bx lr
rt_0200afe4:
    dcd 0x0000041e // Literal/table data, not an instruction.
}

// Compiler runtime support: _ull_mod.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _ll_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_ll_div.s.
// DQIX USA arm9/main: 0x0200CEE8, 60 bytes.
// Original bytes SHA256: ec20ea526d86012a89c9257f431ffe738c379a6ebc77dba608657a429fb29b01.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" void data_0200d158();
extern "C" asm void _ull_mod()
{

rt_0200cee8:
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200ceec:
    mov r4, #1
rt_0200cef0:
    orrs r5, r3, r2
rt_0200cef4:
    bne rt_0200cf00
rt_0200cef8:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cefc:
    bx lr
rt_0200cf00:
    orrs r5, r1, r3
rt_0200cf04:
    dcd RUNTIME_BRANCH(1, -356) // Shared runtime tail target: _ll_sdiv + 116
rt_0200cf08:
    mov r1, r2
rt_0200cf0c:
    bl data_0200d158
rt_0200cf10:
    cmp r4, #0
rt_0200cf14:
    movne r0, r1
rt_0200cf18:
    mov r1, #0
rt_0200cf1c:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cf20:
    bx lr
}

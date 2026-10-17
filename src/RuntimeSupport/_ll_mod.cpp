// Compiler runtime support: _ll_mod.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _ll_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_ll_div.s.
// DQIX USA arm9/main: 0x0200CD1C, 16 bytes.
// Original bytes SHA256: 0cfcdfd477eb7435e397b84772021f2fbf7050853cf54815d11154e2be979bd7.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _ll_mod()
{

rt_0200cd1c:
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cd20:
    mov r4, r1
rt_0200cd24:
    orr r4, r4, #1
rt_0200cd28:
    dcd RUNTIME_BRANCH(14, 20) // Shared runtime tail target: _ll_sdiv + 16
}

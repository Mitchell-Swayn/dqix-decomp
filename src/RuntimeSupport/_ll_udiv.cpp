// Compiler runtime support: _ull_div, _ll_udiv.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _ll_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_ll_div.s.
// DQIX USA arm9/main: 0x0200CEDC, 12 bytes.
// Original bytes SHA256: 1ebc0f6fa62024d985b12560ce08f6c2f79752aed0fd5e0111a55f54acbd802f.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _ll_udiv()
{

rt_0200cedc:
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cee0:
    mov r4, #0
rt_0200cee4:
    dcd RUNTIME_BRANCH(14, 12) // Shared runtime tail target: _ull_mod + 8
}

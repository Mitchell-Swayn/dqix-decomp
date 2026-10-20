// SDK support (community reconstruction): MIi_CpuCopy32.
#pragma thumb off
// SDK support (community reconstruction): MIi_CpuCopy32.
// Labelled SDK community assembly; excluded from C/C++ reconstruction credit.
// Source: pret/pokeheartgold, commit 14c48938174ec92563afc6d03de5fa162f4cfdce,
// lib/NitroSDK/asm/mi_memory.s, MIi_CpuCopy32 (lines 64-81).
// Copies word-aligned memory; r0=source, r1=destination, r2=byte length.
// Original: arm9/main @ 0x020ca408; symbol: func_020ca408; size: 0x28.
// SDK name proposal: MIi_CpuCopy32; original ABI retained for verification.
extern "C" asm void MIi_CpuCopy32(const void *source, void *destination, unsigned int size)
{
    add ip, r1, r2
copy_loop:
    cmp r1, ip
    blt copy_load
    b copy_store_test
copy_load:
    ldmia r0!, {r2}
copy_store_test:
    blt copy_store
    b copy_repeat
copy_store:
    stmia r1!, {r2}
copy_repeat:
    blt copy_loop
    bx lr
}

// SDK support (community reconstruction): MIi_CpuClear32.
// SDK support (community reconstruction): NitroSDK MIi_CpuClear32.
// Original: arm9/main @ 0x020CA3EC; symbol: func_020ca3ec; size: 0x1C.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce lib/NitroSDK/asm/mi_memory.s
// ABI: r0 fill word, r1 destination, r2 byte count; void return.
#pragma thumb off
extern "C" asm void MIi_CpuClear32()
{
    add ip, r1, r2
clear32_compare:
    cmp r1, ip
    blt clear32_store
    b clear32_continue
clear32_store:
    stmia r1!, {r0}
clear32_continue:
    blt clear32_compare
    bx lr
}

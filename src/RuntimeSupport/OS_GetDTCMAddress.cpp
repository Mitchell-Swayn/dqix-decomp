// SDK support (community reconstruction): OS_GetDTCMAddress.
// SDK support (community inline assembly): NitroSDK OS_GetDTCMAddress.
// Original: arm9/main @ 0x020C89E4; symbol: func_020c89e4; size: 0x14.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/src/os/os_tcm.c; unchanged instructions, original ABI retained.
#pragma thumb off
extern "C" asm unsigned long OS_GetDTCMAddress(void) {
    mrc p15, 0, r0, c9, c1, 0
    ldr r1, =0xFFFFF000
    and r0, r0, r1
    bx lr
}

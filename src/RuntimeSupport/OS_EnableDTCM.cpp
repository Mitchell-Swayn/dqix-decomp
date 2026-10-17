// SDK support (community reconstruction): OS_EnableDTCM.
// SDK support (community inline assembly): NitroSDK OS_EnableDTCM.
// Original: arm9/main @ 0x020C89D4; symbol: func_020c89d4; size: 0x10.
// Reference: RushRE/SonicRushAdventure-Decomp@b449036259b8eff92ceb2b226474149bcf8a0a30
// lib/NitroSDK/src/os/ARM9/os_tcm.c, OS_EnableDTCM.
// HW_C1_DTCM_ENABLE = 0x00010000 in lib/include/nitro/hw/common/armArch.h.
// Community SDK assembly; no C/C++ credit.
#pragma thumb off
extern "C" asm void OS_EnableDTCM(void)
{
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #0x10000
    mcr p15, 0, r0, c1, c0, 0
    bx lr
}

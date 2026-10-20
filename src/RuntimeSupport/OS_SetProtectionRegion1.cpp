// SDK support (community reconstruction): OS_SetProtectionRegion1.
// SDK authored assembly reference; no C/C++ reconstruction credit.
// Original: arm9/main @ 0x020C8A2C; symbol: func_020c8a2c; size: 0x8.
// Writes the ARM9 CP15 protection-region1 parameter. Instruction body verbatim.
// Reference: ntrtwl/NitroSDK@9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/os/src/os_protectionRegion.c:106-110.
#pragma thumb off
extern "C" asm void OS_SetProtectionRegion1(unsigned param)
{
    mcr p15, 0, r0, c6, c1, 0
    bx lr
}

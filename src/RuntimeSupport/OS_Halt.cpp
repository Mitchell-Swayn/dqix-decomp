// SDK support (community reconstruction): OS_Halt.
// SDK support (community inline assembly): NitroSDK OS_Halt.
// Original: arm9/main @ 0x020C9BF0; symbol: func_020c9bf0; size: 0x0C.
// Reference: pret/pokeheartgold@9d8b7591f09b65804da2fb2dfd56f320633e0d36
// lib/NitroSDK/src/os/os_terminate_proc.c, OS_Halt under SDK_ARM9.
// Waits for an interrupt with ARM946E-S CP15; zero C/C++ credit.
#pragma thumb off
extern "C" asm void OS_Halt(void)
{
    mov r0, #0
    mcr p15, 0, r0, c7, c0, 4
    bx lr
}

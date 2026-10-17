// SDK support (community reconstruction): OSi_WaitVCount0.
// SDK support (community reconstruction): OSi_WaitVCount0.
// Pinned pret/pokeheartgold os_init.c explicitly declares this routine asm.
// Original: arm9/main @ 0x020C8348; symbol: func_020c8348; size: 0x20.
// Temporarily disables IME, waits for VCOUNT0, restores IME; zero C credit.
#pragma thumb off
extern "C" asm void OSi_WaitVCount0()
{
    mov r12, #0x04000000
    ldr r1, [r12, #0x208]
    str r12, [r12, #0x208]
spinWait:
    ldrh r0, [r12, #6]
    cmp r0, #0
    bne spinWait
    str r1, [r12, #0x208]
    bx lr
}

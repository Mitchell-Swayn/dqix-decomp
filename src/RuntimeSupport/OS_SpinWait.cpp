// SDK support (community reconstruction): OS_SpinWait.
#pragma thumb off
// SDK support (community reconstruction): OS_SpinWait.
// SDK support (community reconstruction): NitroSDK OS_SpinWait.
// Original: arm9/main @ 0x020C976C; symbol: func_020c976c; size: 0xC.
// Pinned pret/pokeheartgold 14c48938174ec92563afc6d03de5fa162f4cfdce, lib/NitroSDK/src/os/os_system.c.
// Busy-waits in four-cycle steps; reconstructed SDK assembly, no C credit.
extern "C" asm void OS_SpinWait(register unsigned cycles) {
@loop:
    subs r0, r0, #4
    bhs @loop
    bx lr
}

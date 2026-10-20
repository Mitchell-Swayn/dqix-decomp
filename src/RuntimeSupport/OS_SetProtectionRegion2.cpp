// Original: arm9/main @ 0x020C8A34; symbol: func_020c8a34.
// SDK support (community reconstruction): OS_SetProtectionRegion2.
// SDK community assembly, not C reconstruction credit.
// ARM9 main, original func_020c8a34 at 0x020c8a34; SDK OS_SetProtectionRegion2.
// pret/pokediamond b623abef1b4dfe204ca50aab42447ac00c134290,
// arm9/lib/NitroSDK/src/OS_protectionRegion.c lines20-24.
// Pinned source SHA256: 561b9339f1208f568756b78f13f30ac2f9f6e2230fbc0cf2f1058a72af5c1ba1
#pragma thumb off
extern "C" asm void OS_SetProtectionRegion2(unsigned parameter)
{
    mcr p15, 0x0, r0, c6, c2, 0x0
    bx lr
}

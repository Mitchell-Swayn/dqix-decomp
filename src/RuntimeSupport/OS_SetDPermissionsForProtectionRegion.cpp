// SDK support (community reconstruction): OS_SetDPermissionsForProtectionRegion.
// SDK support (community reconstruction): OS_SetDPermissionsForProtectionRegion.
// Source: pret/pokeheartgold lib/NitroSDK/src/os/os_protectionRegion.c.
// Commit: 14c48938174ec92563afc6d03de5fa162f4cfdce.
// Pinned source SHA256: 409a2145300071cfe63f46fe443ab8f154b6594c1268d2810d59030d0aeddaf2.
// Original: arm9/main @ 0x020C8A18; symbol: func_020c8a18; size: 0x14.
// Updates MPU data access permissions by clearing setMask and setting flags.
// The pinned reference defines this routine as assembly; body retained verbatim.
// Community reconstruction, no vendor archive assertion or C reconstruction credit.
#pragma thumb off
extern "C" asm void OS_SetDPermissionsForProtectionRegion(register unsigned setMask, register unsigned flags) {
    mrc p15, 0, r2, c5, c0, 2
    bic r2, r2, r0
    orr r2, r2, r1
    mcr p15, 0, r2, c5, c0, 2
    bx lr
}

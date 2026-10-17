// SDK support (community reconstruction): MTX_RotY33_.
// SDK support (community assembly reconstruction): NitroSDK MTX_RotY33_.
// Original: arm9/main @ 0x020C1280; symbol: Mat3x3_WriteRotationY; size: 0x1C.
// Historical ABI name preserved; writes a Y rotation matrix from fx32 sine/cosine.
// Reference: pret/pokeheartgold@9d8b7591f09b65804da2fb2dfd56f320633e0d36
// lib/NitroSDK/asm/fx_mtx33.s, MTX_RotY33_; community assembly, no C credit.
#pragma thumb on
extern "C" asm void MTX_RotY33_(int* matrix, int sine, int cosine)
{
    str r2, [r0]
    str r2, [r0, #0x20]
    mov r3, #0
    str r3, [r0, #4]
    str r3, [r0, #0xc]
    str r3, [r0, #0x14]
    str r3, [r0, #0x1c]
    neg r2, r1
    mov r3, #1
    lsl r3, r3, #0xc
    str r1, [r0, #0x18]
    str r2, [r0, #8]
    str r3, [r0, #0x10]
    bx lr
}

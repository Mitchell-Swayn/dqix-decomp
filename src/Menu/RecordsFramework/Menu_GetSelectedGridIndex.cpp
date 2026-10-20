#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
// Original: arm9/ov023 @ 0x021F9BC8; symbol: func_ov023_021f9bc8; size: 0x14.
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short* obj) {
    return obj[21]+obj[20]*obj[19];
}

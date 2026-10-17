extern "C" char* data_ov031_0224e5c4[4];
// Original: arm9/ov031 @ 0x022134B0; symbol: func_ov031_022134b0; size: 0x1C.
extern "C" unsigned ReadOptionalObjectByteNine() {
    char* p=data_ov031_0224e5c4[3];
    return p ? (unsigned char)p[9] : 0;
}

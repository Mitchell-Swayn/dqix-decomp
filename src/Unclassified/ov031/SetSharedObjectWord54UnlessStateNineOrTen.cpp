extern "C" unsigned* data_ov031_02290d18[2];
// Original: arm9/ov031 @ 0x022393E4; symbol: func_ov031_022393e4; size: 0x20.
extern "C" void SetSharedObjectWord54UnlessStateNineOrTen(unsigned value) {
    unsigned* p=data_ov031_02290d18[1];
    if(p[16]-9>1)p[21]=value;
}

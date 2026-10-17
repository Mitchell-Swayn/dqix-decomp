extern unsigned char data_ov005_0215cd18[8];
// Original: arm9/ov005 @ 0x0215A948; symbol: func_ov005_0215a948; size: 0x18.
extern "C" unsigned func_ov005_0215a948(void* unused, unsigned index) { return index >= 8 ? 0 : data_ov005_0215cd18[index]; }

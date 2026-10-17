extern unsigned char data_ov005_0215cd20[8];
// Original: arm9/ov005 @ 0x0215A930; symbol: func_ov005_0215a930; size: 0x18.
extern "C" unsigned func_ov005_0215a930(void* unused, unsigned index) { return index >= 8 ? 0 : data_ov005_0215cd20[index]; }

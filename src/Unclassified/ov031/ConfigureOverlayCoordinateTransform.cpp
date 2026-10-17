#include <globaldefs.h>
ARM
extern "C" unsigned data_ov031_02290ce8[];
extern "C" void* Graphics_CopySixteenHalfwordsToEdgeColorRegisters;
extern "C" void Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, void*, unsigned, unsigned);
// Original: arm9/ov031 @ 0x02234FF8; symbol: func_ov031_02234ff8; size: 0x3C.
extern "C" void ConfigureOverlayCoordinateTransform(unsigned base, unsigned index, unsigned position) {
    data_ov031_02290ce8[1] = base + (index << 5);
    data_ov031_02290ce8[2] = (position << 5) + 0x05000000;
    Unclassified_InvokeHelperWithZeroFifthArgument(1, &Graphics_CopySixteenHalfwordsToEdgeColorRegisters, 0, 0x78);
}

#include <globaldefs.h>
ARM
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*, unsigned);
extern "C" void LoadToMainBG2ScreenData(const void*, unsigned, unsigned);
extern "C" void* volatile data_ov031_02290ce8;
// Original: arm9/ov031 @ 0x02234FA4; symbol: func_ov031_02234fa4; size: 0x54.
extern "C" void Overlay_LoadPendingBG2ScreenData(void) {
    void* buffer = data_ov031_02290ce8;
    if (*(volatile unsigned char*)((char*)buffer + 0x604) == 0) return;
    _Z25CleanInvalidateCacheRangePKvj((char*)buffer + 4, 0x600);
    buffer = data_ov031_02290ce8;
    LoadToMainBG2ScreenData((char*)buffer + 4, 0, 0x600);
    buffer = data_ov031_02290ce8;
    *(volatile unsigned char*)((char*)buffer + 0x604) = 0;
}

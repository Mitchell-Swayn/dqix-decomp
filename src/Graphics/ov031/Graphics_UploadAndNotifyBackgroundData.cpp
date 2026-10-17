#include <globaldefs.h>
ARM

extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void *, unsigned int);
extern "C" void LoadToSubBG1ScreenData(const void *, unsigned int, unsigned int);
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void *);
extern "C" void func_ov031_0223e2c0(int, void *);
extern "C" void * volatile data_ov031_02290d04;

// Original: arm9/ov031 @ 0x022373FC; symbol: func_ov031_022373fc; size: 0x4C.
extern "C" void Graphics_UploadAndNotifyBackgroundData(void *value) {
    _Z25CleanInvalidateCacheRangePKvj(data_ov031_02290d04, 0x600);
    LoadToSubBG1ScreenData(data_ov031_02290d04, 0, 0x600);
    Unclassified_FreeArgumentAndUpdateGlobalOwner(data_ov031_02290d04);
    func_ov031_0223e2c0(1, value);
}

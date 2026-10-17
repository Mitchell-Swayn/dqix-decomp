#include <globaldefs.h>
ARM
extern "C" void* data_ov031_0224bedc[];
extern "C" void* data_ov031_02290d04;
extern "C" void* Graphics_UploadAndNotifyBackgroundData;
extern "C" void* Unclassified_CopyStringAndNormalizeMarker(void*);
extern "C" unsigned func_ov031_0223b61c(void*, unsigned, unsigned);
extern "C" void Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, void*, unsigned, unsigned);
// Original: arm9/ov031 @ 0x022373B4; symbol: func_ov031_022373b4; size: 0x48.
extern "C" void ConfigureIndexedOverlayResource(unsigned index) {
    void* resource = Unclassified_CopyStringAndNormalizeMarker(data_ov031_0224bedc[index]);
    unsigned handle = func_ov031_0223b61c(resource, 0, 4);
    data_ov031_02290d04 = (void*)handle;
    Unclassified_InvokeHelperWithZeroFifthArgument(1, &Graphics_UploadAndNotifyBackgroundData, 0, 0x78);
}

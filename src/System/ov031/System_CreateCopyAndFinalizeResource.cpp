#include <globaldefs.h>
ARM
extern "C" void* Unclassified_CopyStringAndNormalizeMarker(void*);
extern "C" void* func_ov031_0223b61c(void*, unsigned, unsigned);
extern "C" void MIi_CpuCopyFast(const void*, void*, unsigned);
extern "C" void Unclassified_FreeArgumentAndUpdateGlobalOwner(void*);
extern "C" void* Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, void (*)(void*), unsigned, unsigned);
extern "C" void* data_ov031_0224b3c0[];
extern "C" unsigned char* data_ov031_02250bf4;
extern "C" void LoadAndSelectMainBG1Data(void*);
// Original: arm9/ov031 @ 0x02223998; symbol: func_ov031_02223998; size: 0x5C.
extern "C" void System_CreateCopyAndFinalizeResource(unsigned index) {
    void* base = Unclassified_CopyStringAndNormalizeMarker(data_ov031_0224b3c0[index]);
    void* destination = func_ov031_0223b61c(base, 0, 4);
    MIi_CpuCopyFast(destination, data_ov031_02250bf4, 0xc0);
    Unclassified_FreeArgumentAndUpdateGlobalOwner(destination);
    Unclassified_InvokeHelperWithZeroFifthArgument(1, LoadAndSelectMainBG1Data, 0, 0x78);
}

#include <globaldefs.h>
#include <Graphics/NSBXX/JACInternal.h>
ARM
extern "C" void MIi_CpuCopyFast(const void *, void *, unsigned int);
extern "C" void *Memory_AllocateZeroedBlock(unsigned int, unsigned int);
extern "C" void * volatile data_ov031_02290ce8;
extern "C" void Overlay_LoadPendingBG2ScreenData(void);
extern "C" unsigned int Unclassified_InvokeHelperWithZeroFifthArgument(unsigned int, void (*)(void), unsigned int, unsigned int);
// Original: arm9/ov031 @ 0x02234EA8; symbol: func_ov031_02234ea8; size: 0x60.
extern "C" void System_CopyContextAndRegisterCallback(void *source) {
    void *resource = Memory_AllocateZeroedBlock(0x608, 4);
    data_ov031_02290ce8 = resource;
    MIi_CpuCopyFast(source, (char *)resource + 4, 0x600);
    unsigned int handle = Unclassified_InvokeHelperWithZeroFifthArgument(1, Overlay_LoadPendingBG2ScreenData, 0, 0x78);
    *(unsigned int *)data_ov031_02290ce8 = handle;
}

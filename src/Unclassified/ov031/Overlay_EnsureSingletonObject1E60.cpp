#include <globaldefs.h>
ARM
extern "C" void* data_ov031_02290cf8;
extern "C" void* Memory_AllocateZeroedBlock(void*, unsigned);
// Original: arm9/ov031 @ 0x02235780; symbol: func_ov031_02235780; size: 0x34.
extern "C" void Overlay_EnsureSingletonObject1E60(void) {
    if (data_ov031_02290cf8 != 0) return;
    data_ov031_02290cf8 = Memory_AllocateZeroedBlock((void*)0x1e60, 0x20);
}

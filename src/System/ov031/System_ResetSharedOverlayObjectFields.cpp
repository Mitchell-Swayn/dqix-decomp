#include <globaldefs.h>
extern "C" volatile unsigned data_ov031_02290d18[];
// Original: arm9/ov031 @ 0x0223932C; symbol: func_ov031_0223932c; size: 0x3C.
extern "C" void System_ResetSharedOverlayObjectFields(void* object) {
    data_ov031_02290d18[1] = (unsigned)object;
    *(unsigned*)((char*)object + 0x40) = 0;
    *(unsigned*)((char*)(void*)data_ov031_02290d18[1] + 0x13a8) = 0;
    *(unsigned*)((char*)(void*)data_ov031_02290d18[1] + 0x13ac) = 0;
    *(unsigned*)((char*)(void*)data_ov031_02290d18[1] + 0x13b0) = 0;
}

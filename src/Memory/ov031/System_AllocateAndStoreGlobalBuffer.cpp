#include <globaldefs.h>
ARM
extern "C" void *Memory_AllocateZeroedBlock(int count, int size);
extern "C" unsigned char data_ov031_02250bf0[];
// Original: arm9/ov031 @ 0x022236E8; symbol: func_ov031_022236e8; size: 0x20.
extern "C" void System_AllocateAndStoreGlobalBuffer(void) {
    *(void **)data_ov031_02250bf0 = Memory_AllocateZeroedBlock(0x10, 4);
}

#include <globaldefs.h>
THUMB
extern "C" unsigned char data_ov031_0224e6e0[];
extern "C" void func_ov031_0221c4ac(int argument);
// Original: arm9/ov031 @ 0x0221CFDC; symbol: func_ov031_0221cfdc; size: 0x2C.
extern "C" void FreeAndClearTwoGlobalObjects(void) {
    if (*(unsigned int *)(data_ov031_0224e6e0 + 0xc)) {
        func_ov031_0221c4ac(*(unsigned int *)(data_ov031_0224e6e0 + 0xc));
        *(unsigned int *)(data_ov031_0224e6e0 + 0xc) = 0;
    }
    if (*(unsigned int *)(data_ov031_0224e6e0 + 4)) {
        func_ov031_0221c4ac(*(unsigned int *)(data_ov031_0224e6e0 + 4));
        *(unsigned int *)(data_ov031_0224e6e0 + 4) = 0;
    }
}

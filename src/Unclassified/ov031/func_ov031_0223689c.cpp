#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290d00;
extern "C" void ResourceHandle_SetOptionalByte41(void *, unsigned int);
// Original: arm9/ov031 @ 0x0223689C; symbol: func_ov031_0223689c; size: 0x20.
extern "C" void func_ov031_0223689c(unsigned int value) {
    ResourceHandle_SetOptionalByte41((unsigned char *)(*(unsigned int *)&data_ov031_02290d00) + 0x94, value);
}

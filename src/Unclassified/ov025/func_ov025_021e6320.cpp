#include <globaldefs.h>
ARM
extern "C" unsigned char data_02108760;
extern "C" void UpdateObjectStateAndStoredValue(void *, unsigned int, unsigned short);
// Original: arm9/ov025 @ 0x021E6320; symbol: func_ov025_021e6320; size: 0x20.
extern "C" int func_ov025_021e6320(void *p) {
    UpdateObjectStateAndStoredValue(&data_02108760, *(unsigned short *)((char *)p + 8), *(unsigned short *)((char *)p + 0xa));
    return 1;
}

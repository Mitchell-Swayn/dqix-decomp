#include <globaldefs.h>
ARM
extern "C" void* data_ov004_021707d8;
// Original: arm9/ov004 @ 0x021570F0; symbol: func_ov004_021570f0; size: 0x38.
extern "C" int func_ov004_021570f0(int index) {
    if (index < 0)
        return -1;
    char* object = *(char**)((char*)&data_ov004_021707d8 + 8);
    if (index >= *(short*)(object + 0x3a))
        return -1;
    return (signed char)*(short*)(object + 0x32 + index * 2);
}

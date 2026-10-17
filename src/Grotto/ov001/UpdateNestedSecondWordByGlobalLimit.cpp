#include <globaldefs.h>
ARM
extern "C" unsigned char data_02114e54[];
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x0215AEB8; symbol: func_ov001_0215aeb8; size: 0x38.
extern "C" int UpdateNestedSecondWordByGlobalLimit(void* object) {
    int enabled = 0;
    if (data_02114e54[0x54] != 0 && *(unsigned*)(data_02114e54 + 0x44) < 0xa) enabled = 1;
    SetNestedSecondWordForTypeThree(object, enabled);
    return 1;
}

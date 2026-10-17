#include <globaldefs.h>
ARM
extern "C" unsigned char *data_ov031_02290d60;
extern "C" int func_ov031_0223bfa0(unsigned int value);
// Original: arm9/ov031 @ 0x0223DA38; symbol: func_ov031_0223da38; size: 0x20.
extern "C" int Ov031_ForwardGlobalIndexedWord(unsigned int index) {
    unsigned int value = *(unsigned int *)(data_ov031_02290d60 + index * 4 + 0x800);
    return func_ov031_0223bfa0(value);
}

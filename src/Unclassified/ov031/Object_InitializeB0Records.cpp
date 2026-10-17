#include <globaldefs.h>
ARM
extern "C" int func_ov031_02211aec(void *destination, int index, int count);
extern "C" void VectorizedMemset(void *destination, int value, unsigned length);
extern "C" int func_ov031_0223f264(void *destination, int index, int count);
// Original: arm9/ov031 @ 0x02212C3C; symbol: func_ov031_02212c3c; size: 0x48.
extern "C" int Object_InitializeB0Records(void *destination, int index, int count) {
    if (func_ov031_02211aec(destination, index, count)) return 0;
    VectorizedMemset(destination, 0, count * 0xb0);
    return func_ov031_0223f264(destination, index, count);
}

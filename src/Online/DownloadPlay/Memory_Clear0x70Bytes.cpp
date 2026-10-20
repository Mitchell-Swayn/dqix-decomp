#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *destination, int value, unsigned int length);
// Original: arm9/ov027 @ 0x021DD104; symbol: func_ov027_021dd104; size: 0x14.
extern "C" void Memory_Clear0x70Bytes(void *destination) {
    VectorizedMemset(destination, 0, 0x70);
}

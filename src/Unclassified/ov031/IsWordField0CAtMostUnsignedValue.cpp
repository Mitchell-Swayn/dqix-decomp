#include <globaldefs.h>

// Original: arm9/ov031 @ 0x022407E4; symbol: func_ov031_022407e4; size: 0x14.
extern "C" ARM int IsWordField0CAtMostUnsignedValue(void* object, unsigned value) {
    return *(unsigned*)((char*)object + 0x0c) <= value;
}

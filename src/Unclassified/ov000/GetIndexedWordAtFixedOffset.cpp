#include <globaldefs.h>

// Original: arm9/ov000 @ 0x021761ec; symbol: func_ov000_021761ec; size: 0x24.
extern "C" void* ReadIndexedWordAtFixedOffset(void* object, int index) {
    if (index < 0 || index >= 8) index = 0;
    return *(void**)((unsigned char*)object + 0x1d3c + index * 4);
}

#include <globaldefs.h>
// func_020bbc68: 0x020bbc68–0x020bbc78, arm; 16 bytes
// Original: arm9/main @ 0x020BBC68; symbol: func_020bbc68; size: 0x10.
extern "C" int Graphics_GetCurrentTransferQueueEntry(const int* base) {
    return *base + ((unsigned int)*(unsigned short*)((const char*)base + 8) << 4);
}

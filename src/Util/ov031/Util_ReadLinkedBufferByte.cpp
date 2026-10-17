#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct Block { Block* next; char bytes[512]; };
struct Buffer { char pad[28]; Block* next; char bytes[1024]; };
// Original: arm9/ov031 @ 0x0224046C; symbol: func_ov031_0224046c; size: 0x7C.
extern "C" int Util_ReadLinkedBufferByte(Buffer* buffer, Block** block, int* index) {
    if (*block == 0) {
        if (*index < 1024) return buffer->bytes[(*index)++];
        *index = 0;
        *block = buffer->next;
    } else if (*index == 512) {
        *index = 0;
        *block = (*block)->next;
    }
    return (*block)->bytes[(*index)++];
}

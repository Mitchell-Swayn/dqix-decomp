#include <globaldefs.h>
ARM
#pragma force_active on
// Original: arm9/ov023 @ 0x021F6C90; symbol: func_ov023_021f6c90; size: 0x84.
// Finds the first unreserved contiguous sprite-slot run; returns -1 when none starts below 128.
extern "C" int MenuRecordList_FindFreeSpriteSlotRange(void* registry, unsigned int screen, unsigned int count) {
    for (int first = 0; first < 128; ++first) {
        int free = 1;
        unsigned int slot = first;
        for (unsigned short i = 0; i < count; ++slot, ++i) {
            if (((unsigned int*)((unsigned char*)registry + 8 + screen * 16))[(int)(slot >> 2)] & (1u << (slot & 3))) {
                free = 0;
                break;
            }
        }
        if (free) return first;
    }
    return -1;
}

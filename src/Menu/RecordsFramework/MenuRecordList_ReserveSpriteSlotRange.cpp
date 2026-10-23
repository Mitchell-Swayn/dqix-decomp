#include <globaldefs.h>
ARM
#pragma force_active on
// Screen bitmap bases are separated by 16 bytes at record-list offset 8.
// The original divides slot indices by four and uses bits 0..3 of each word.
// Original: arm9/ov023 @ 0x021F6BEC; symbol: func_ov023_021f6bec; size: 0x50.
// Reserves every slot in the requested range; a first slot >= 128 is ignored.
extern "C" void MenuRecordList_ReserveSpriteSlotRange(void* registry, unsigned int screen, unsigned int first, unsigned int count) {
    if (first >= 128) return;
    unsigned int* bitmap = ((unsigned int*)((unsigned char*)registry + 8 + screen * 16));
    for (unsigned short i = 0; i < count; ++first, ++i)
        bitmap[(int)(first >> 2)] |= 1u << (first & 3);
}

#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0216FE74; symbol: Unclassified_GetIndexedRecordFromCountedArray; size: 0x28.
// Returns base + index*0x28 when the pointer at +0x40 is nonnull and index is below the halfword count at +0x4E; otherwise returns null.
extern "C" void *BattleMenu_GetSpriteResourceEntry(unsigned char *p, unsigned int index) {
    unsigned int result = 0;
    unsigned char *base = *(unsigned char **)(p + 0x40);
    if (base) {
        if (index < *(unsigned short *)(p + 0x4e)) result = index * 0x28 + (unsigned int)base;
    }
    return (void *)result;
}

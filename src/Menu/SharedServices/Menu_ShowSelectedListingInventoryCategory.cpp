#include <globaldefs.h>
ARM
extern "C" int GetTypeSevenRowMajorIndex(void *self, unsigned key);
extern "C" void GameState_ClearMaskFromKeyedEntry(void *self, unsigned int value, unsigned char mask);
// Original: arm9/ov004 @ 0x0215B710; symbol: GameState_ClearTypeSevenEntryMask; size: 0x30.
// Finds type-seven key 0x65 and clears mask 8 at the corresponding state index plus 0x38c.
extern "C" int Menu_ShowSelectedListingInventoryCategory(void *self, unsigned key) {
    int index = GetTypeSevenRowMajorIndex(self, 0x65);
    if (index >= 0) GameState_ClearMaskFromKeyedEntry(self, (unsigned int)(index + 0x38c), 8);
    return 0;
}

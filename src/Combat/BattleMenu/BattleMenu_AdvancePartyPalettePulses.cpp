#include <globaldefs.h>
ARM
extern "C" void* BattleMenu_FindPartyCommandRecord(void*, int);
extern "C" void BattleHud_UpdateSlotHighlightPalette(void*, int);
// Original: arm9/ov000 @ 0x021754FC; symbol: ApplyValueToPresentRecordsInFourSlots; size: 0x48.
// Reads four signed slot indices from self +0x6C and applies the supplied value to each slot record that exists.
extern "C" void BattleMenu_AdvancePartyPalettePulses(unsigned char* self, int value) {
    unsigned char i = 0;
    while (i < 4) {
        int index = *(signed char*)(self + i + 0x6c);
        void* record = BattleMenu_FindPartyCommandRecord(self, index);
        if (record) BattleHud_UpdateSlotHighlightPalette(record, value);
        ++i;
    }
}

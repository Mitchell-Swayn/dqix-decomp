#include <globaldefs.h>
ARM
extern "C" int BattleMenu_CountSpellChoices(void *entries);
// Original: arm9/ov000 @ 0x02171640; symbol: func_ov000_02171640; size: 0x34.
// For a valid index below 66 and nonnull value, stores the pointer and refreshes the halfword nonzero-entry count.
extern "C" void BattleMenu_SetSpellChoice(void *entries, int index, void *value) {
    if (index < 0 || index >= 0x42 || value == 0) return;
    *(void **)((char *)entries + index * 4 + 0x9c) = value;
    *(unsigned short *)((char *)entries + 0x82) = (unsigned short)BattleMenu_CountSpellChoices(entries);
}

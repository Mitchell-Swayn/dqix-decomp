#include <globaldefs.h>
ARM
extern "C" int BattleMenu_CountValidItemChoices(unsigned char *base);
// Original: arm9/ov000 @ 0x02171B68; symbol: func_ov000_02171b68; size: 0x34.
extern "C" void BattleMenu_SetItemChoice(unsigned char *base, int index, void *value) {
    if (index < 0 || index >= 16 || value == 0) {
        return;
    }
    *(void **)(base + index * 4 + 0x3F0) = value;
    base[0x86] = (unsigned char)BattleMenu_CountValidItemChoices(base);
}

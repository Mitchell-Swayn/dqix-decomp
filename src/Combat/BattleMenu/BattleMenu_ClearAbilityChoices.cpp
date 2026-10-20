#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0217193C; symbol: Memory_Clear147ObjectWordsAndHalfwordAt84; size: 0x2C.
// Clears 147 words starting at object offset 0x1A4, then clears the halfword at offset 0x84.
extern "C" void BattleMenu_ClearAbilityChoices(void *p) {
    for (int i = 0; i < 0x93; ++i)
        *(int *)((char *)p + 0x1a4 + i * 4) = 0;
    *(unsigned short *)((char *)p + 0x84) = 0;
}

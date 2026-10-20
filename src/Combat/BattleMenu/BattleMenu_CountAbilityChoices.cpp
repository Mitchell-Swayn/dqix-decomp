#include <globaldefs.h>

// Original: arm9/ov000 @ 0x021719c0; symbol: func_ov000_021719c0; size: 0x38.
extern "C" int BattleMenu_CountAbilityChoices(void* object) {
    short count = 0;
    for (int i = 0; i < 0x93; i++) {
        if (*(unsigned int*)((unsigned char*)object + 0x1a4 + i * 4) != 0) count = (short)(count + 1);
    }
    return count;
}

#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02162C90; symbol: func_ov000_02162c90; size: 0x2C.
extern "C" void CombatScene_SetPartySelectionSyncValue(void *base, int index, unsigned int value) {
    int valid;
    if (index < 0) goto invalid;
    if (index <= 3) {
        valid = 1;
        goto checked;
    }
invalid:
    valid = 0;
checked:
    if (valid)
        *(unsigned int *)((char *)base + 0x54f4 + index * 4) = value;
}

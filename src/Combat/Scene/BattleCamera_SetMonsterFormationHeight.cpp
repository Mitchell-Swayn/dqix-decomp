#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F720; symbol: Combat_SetWordAtOffset234; size: 0x8.
// Stores a 32-bit value at object byte offset 0x234.
ARM
extern "C" void BattleCamera_SetMonsterFormationHeight(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x234) = value;
}

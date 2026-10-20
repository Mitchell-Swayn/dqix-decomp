#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F718; symbol: Combat_SetWordAtOffset230; size: 0x8.
// Stores a 32-bit value at object byte offset 0x230.
ARM
extern "C" void BattleCamera_SetMonsterFormationWidth(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x230) = value;
}

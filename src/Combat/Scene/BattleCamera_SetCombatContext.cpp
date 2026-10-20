#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F700; symbol: Combat_SetWordAtOffset21C; size: 0x8.
// Stores a 32-bit value at object byte offset 0x21c.
ARM
extern "C" void BattleCamera_SetCombatContext(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x21c) = value;
}

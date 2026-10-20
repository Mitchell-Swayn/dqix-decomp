#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F710; symbol: Combat_SetWordAtOffset22C; size: 0x8.
// Stores a 32-bit value at object byte offset 0x22c.
ARM
extern "C" void BattleCamera_SetPartyFormationHeight(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x22c) = value;
}

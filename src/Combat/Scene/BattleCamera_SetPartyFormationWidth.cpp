#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216F708; symbol: Combat_SetWordAtOffset228; size: 0x8.
// Stores a 32-bit value at object byte offset 0x228.
ARM
extern "C" void BattleCamera_SetPartyFormationWidth(void *object, unsigned int value) {
    *(unsigned int *)((unsigned char *)object + 0x228) = value;
}

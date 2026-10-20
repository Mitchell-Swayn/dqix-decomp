#include <globaldefs.h>
ARM
// Original: arm9/ov017 @ 0x021972F8; symbol: GameState_AppendHalfwordToFourEntryRingBuffer; size: 0x2C.
// Writes the halfword at the current ring slot, advances the byte index, then wraps it to two bits.
extern "C" void Field_RememberRecentEncounterIdentifier(void *object, unsigned short value) {
    unsigned char *counter = (unsigned char *)object + 0x44c0;
    unsigned index = *counter;
    *counter = (unsigned char)(index + 1);
    *(unsigned short *)((char *)object + 0x44b8 + index * 2) = value;
    *counter &= 3;
}

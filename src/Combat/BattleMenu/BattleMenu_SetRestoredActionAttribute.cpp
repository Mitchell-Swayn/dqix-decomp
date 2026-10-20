#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0216FF20; symbol: Combat_SetByteAtOffset25; size: 0x8.
// Stores the low byte of the value at object byte offset 0x25.
ARM
extern "C" void BattleMenu_SetRestoredActionAttribute(void *object, unsigned char value) {
    *((unsigned char *)object + 0x25) = value;
}

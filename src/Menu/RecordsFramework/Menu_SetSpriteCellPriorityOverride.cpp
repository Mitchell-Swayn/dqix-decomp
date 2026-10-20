#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB284; symbol: WriteByteAtOffset39; size: 0x8.
// Accesses the byte at object offset 0x39; field meaning is not established.
extern "C" void Menu_SetSpriteCellPriorityOverride(void *object, unsigned char value) { *((unsigned char *)object + 0x39) = value; }

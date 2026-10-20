#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB2A8; symbol: WriteByteAtOffset4A; size: 0x8.
// Accesses the byte at object offset 0x4A; field meaning is not established.
extern "C" void Menu_RequestSpriteCellRightDrawNudge(void *object, unsigned char value) { *((unsigned char *)object + 0x4a) = value; }

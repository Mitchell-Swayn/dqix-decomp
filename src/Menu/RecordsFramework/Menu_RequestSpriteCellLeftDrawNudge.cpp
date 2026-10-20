#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB2A0; symbol: WriteByteAtOffset4B; size: 0x8.
// Accesses the byte at object offset 0x4B; field meaning is not established.
extern "C" void Menu_RequestSpriteCellLeftDrawNudge(void *object, unsigned char value) { *((unsigned char *)object + 0x4b) = value; }

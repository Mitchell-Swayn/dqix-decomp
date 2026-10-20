#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB524; symbol: WriteHalfwordAtOffset26; size: 0x8.
// Accesses the halfword at object offset 0x26; field meaning is not established.
extern "C" void Menu_SetSpriteTrackParameterAt26(void *object, unsigned short value) { *(unsigned short *)((unsigned char *)object + 0x26) = value; }

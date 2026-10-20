#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB52C; symbol: ReadHalfwordAtOffset26; size: 0x8.
// Accesses the halfword at object offset 0x26; field meaning is not established.
extern "C" unsigned short Menu_GetSpriteTrackParameterAt26(void *object) { return *(unsigned short *)((unsigned char *)object + 0x26); }

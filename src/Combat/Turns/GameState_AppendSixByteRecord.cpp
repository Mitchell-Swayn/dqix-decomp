#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x021633B8; symbol: func_ov000_021633b8; size: 0x4C.
// Increments the byte count at 0x5900 and copies two halfwords plus two bytes into the next six-byte slot at 0x58D0.
extern "C" void GameState_AppendSixByteRecord(void *base, const void *record) {
    unsigned char index = *(unsigned char *)((char *)base + 0x5900);
    *(unsigned char *)((char *)base + 0x5900) = index + 1;
    char *slot = (char *)base + 0x58d0 + index * 6;
    *(unsigned short *)slot = *(const unsigned short *)record;
    *(unsigned short *)(slot + 2) = *(const unsigned short *)((const char *)record + 2);
    *(unsigned char *)(slot + 4) = *(const unsigned char *)((const char *)record + 4);
    *(signed char *)(slot + 5) = *(const signed char *)((const char *)record + 5);
}

#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *, unsigned char, int);
// Original: arm9/ov006 @ 0x02158054; symbol: func_ov006_02158054; size: 0x2C.
extern "C" void KrakPot_SubmitControlSprite(void *owner, unsigned char *record, int x, int y, unsigned char firstByte, unsigned char secondByte) {
    *(unsigned int *)(record + 0x14) = (unsigned int)x << 12;
    *(unsigned int *)(record + 0x18) = (unsigned int)y << 12;
    record[0x22] = firstByte;
    record[0x26] = secondByte;
    Graphics_SubmitTransformedCellToOam(owner, record, secondByte, y);
}

#include <globaldefs.h>
ARM
extern "C" void *SpriteResources_GetCellByIndex(void *, unsigned);
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *);
// Original: arm9/ov003 @ 0x02173B4C; symbol: func_ov003_02173b4c; size: 0x64.
extern "C" void TagMode_DrawCancelButton(unsigned char *object) {
    unsigned int state = object[0xec];
    if (state == 0) return;
    if (state == 1 && object[0xee] < 2) return;
    unsigned int index = 6;
    if (object[0]) index = 7;
    unsigned char *record = (unsigned char *)SpriteResources_GetCellByIndex(object + 0x130, index);
    if (!record) return;
    *(unsigned int *)(record + 0x14) = 0x44000;
    *(unsigned int *)(record + 0x18) = 0x5f000;
    Graphics_SubmitTransformedCellToOam(object + 0x130, record);
}

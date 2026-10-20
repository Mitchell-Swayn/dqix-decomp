#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void*, void*);
// Original: arm9/ov003 @ 0x021604F4; symbol: World_SetIndexedPositionRecordAndSubmit; size: 0x38.
// Writes fixed-point x/y and flag into the indexed 0x28-byte record, then submits it.
extern "C" void Tavern_SubmitMenuSpriteAtPosition(void* self, int x, int y, short index, unsigned char flag) {
    char* record = *(char**)((char*)self + 0x388) + index * 0x28;
    *(int*)(record + 0x14) = x << 12;
    *(int*)(record + 0x18) = y << 12;
    *(unsigned char*)(record + 0x22) = flag;
    Graphics_SubmitTransformedCellToOam((char*)self + 0x334, record);
}

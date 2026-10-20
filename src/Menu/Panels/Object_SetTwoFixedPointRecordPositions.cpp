#include <globaldefs.h>
extern "C" void Graphics_SubmitTransformedCellToOam(void*, void*);
// Original: arm9/ov023 @ 0x021E31E4; symbol: func_ov023_021e31e4; size: 0x74.
extern "C" void Object_SetTwoFixedPointRecordPositions(void* object, int x, int y, int z, short w) {
    unsigned char* record = *(unsigned char**)((char*)object + 0xcc);
    *(int*)(record + 0xb4) = x << 12;
    *(int*)(record + 0xb8) = y << 12;
    record[0xc2] = 0x78;
    record[0xc6] = 2;
    Graphics_SubmitTransformedCellToOam(*(void**)((char*)object + 0xc8), record + 0xa0);
    record = *(unsigned char**)((char*)object + 0xcc);
    *(int*)(record + 0xdc) = z << 12;
    *(int*)(record + 0xe0) = (int)w << 12;
    record[0xea] = 0x77;
    record[0xee] = 2;
    Graphics_SubmitTransformedCellToOam(*(void**)((char*)object + 0xc8), record + 0xc8);
}

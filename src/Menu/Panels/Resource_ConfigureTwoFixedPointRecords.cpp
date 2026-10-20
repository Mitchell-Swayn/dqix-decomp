#include <globaldefs.h>
ARM
extern "C" void Graphics_SubmitTransformedCellToOam(void*, void*);
// Original: arm9/ov023 @ 0x021E3258; symbol: func_ov023_021e3258; size: 0x74.
extern "C" void Resource_ConfigureTwoFixedPointRecords(unsigned char* object, int x, int y, int z, short w) {
    unsigned char* records = *(unsigned char**)(object + 0xcc);
    *(int*)(records + 0x104) = x << 12;
    *(int*)(records + 0x108) = y << 12;
    records[0x112] = 0x76;
    records[0x116] = 2;
    Graphics_SubmitTransformedCellToOam(*(void**)(object + 0xc8), records + 0xf0);
    records = *(unsigned char**)(object + 0xcc);
    *(int*)(records + 0x12c) = z << 12;
    *(int*)(records + 0x130) = (int)w << 12;
    records[0x13a] = 0x75;
    records[0x13e] = 2;
    Graphics_SubmitTransformedCellToOam(*(void**)(object + 0xc8), records + 0x118);
}

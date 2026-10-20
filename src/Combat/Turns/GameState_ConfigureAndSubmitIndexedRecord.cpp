#include <globaldefs.h>
ARM

extern "C" int GameState_ClassifyIndexedRecord(char *, int);
extern "C" void Graphics_SubmitTransformedCellToOam(void *, void *);

// Original: arm9/ov000 @ 0x021811F4; symbol: func_ov000_021811f4; size: 0x58.
extern "C" void GameState_ConfigureAndSubmitIndexedRecord(void *object, int index, int x, int y) {
    unsigned char *base = (unsigned char *)object;
    unsigned char *record = (unsigned char *)(*(unsigned int *)(base + 0x170)) + (index + 0x24) * 0x28;
    *(int *)(record + 0x14) = x << 12;
    *(int *)(record + 0x18) = y << 12;
    record[0x22] = (unsigned char)(index + 0x48);
    record[0x26] = 1;
    record[0x25] = (unsigned char)GameState_ClassifyIndexedRecord((char *)object, (signed char)index);
    Graphics_SubmitTransformedCellToOam(base + 0x11C, record);
}

#include <globaldefs.h>
extern "C" void Graphics_SubmitTransformedCellToOam(void*, void*);
// Original: arm9/ov003 @ 0x0216DEE4; symbol: func_ov003_0216dee4; size: 0x54.
extern "C" ARM void Ov003_ConfigureIndexedRecord(void* owner, unsigned index, int x, int y, int stateA, int stateB, int stateC) {
    unsigned char* record = (unsigned char*)(*(unsigned char**)((char*)owner + 0x40) + index * 0x28);
    if (!record) return;
    *(int*)(record + 0x14) = x << 12;
    *(int*)(record + 0x18) = y << 12;
    if (stateA >= 0) record[0x22] = (unsigned char)stateA;
    if (stateB >= 0) record[0x25] = (unsigned char)stateB;
    if (stateC >= 0) record[0x26] = (unsigned char)stateC;
    Graphics_SubmitTransformedCellToOam(owner, record);
}

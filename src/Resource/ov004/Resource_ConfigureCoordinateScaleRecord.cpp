#include <globaldefs.h>
ARM
extern "C" void* func_ov011_021849c8(void* state);
extern "C" void* func_ov023_021f6880(void** head, unsigned short value);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
// Original: arm9/ov004 @ 0x0216AED0; symbol: func_ov004_0216aed0; size: 0x54.
extern "C" void Resource_ConfigureCoordinateScaleRecord(void* state, unsigned short index, unsigned short value, int enable) {
    void* list = func_ov011_021849c8(state);
    void* record = func_ov023_021f6880((void**)list, index);
    if (record == 0) return;
    if (OV023_ReadHalfwordField04(record) != 8) return;
    *(unsigned short*)((char*)record + 0x38) = value;
    if (enable != 1) return;
    unsigned char flags = *(unsigned char*)((char*)record + 0x45);
    flags = (flags & ~0x7E) | 4;
    *(unsigned char*)((char*)record + 0x45) = flags;
    *(unsigned short*)((char*)record + 0x42) = 0;
}

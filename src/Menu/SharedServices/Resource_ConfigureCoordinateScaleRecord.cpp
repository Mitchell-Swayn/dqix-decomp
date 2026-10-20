#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void* state);
extern "C" void* MenuRecordList_LocateByKey(void** head, unsigned short value);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x0216AED0; symbol: func_ov004_0216aed0; size: 0x54.
extern "C" void Resource_ConfigureCoordinateScaleRecord(void* state, unsigned short index, unsigned short value, int enable) {
    void* list = Menu_GetDisplayRecordRegistry(state);
    void* record = MenuRecordList_LocateByKey((void**)list, index);
    if (record == 0) return;
    if (MenuRecord_GetType(record) != 8) return;
    *(unsigned short*)((char*)record + 0x38) = value;
    if (enable != 1) return;
    unsigned char flags = *(unsigned char*)((char*)record + 0x45);
    flags = (flags & ~0x7E) | 4;
    *(unsigned char*)((char*)record + 0x45) = flags;
    *(unsigned short*)((char*)record + 0x42) = 0;
}

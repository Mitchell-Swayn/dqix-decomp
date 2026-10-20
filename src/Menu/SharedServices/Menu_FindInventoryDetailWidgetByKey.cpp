#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x02157054; symbol: func_ov004_02157054; size: 0x34.
extern "C" void* Menu_FindInventoryDetailWidgetByKey(void* state, unsigned short key) {
    void* head = Menu_GetDisplayRecordRegistry(state);
    void* entry = MenuRecordList_LocateByKey((void**)head, key);
    if (entry && MenuRecord_GetType(entry) == 0x10)
        return entry;
    return 0;
}

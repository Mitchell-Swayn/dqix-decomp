#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x02156ED0; symbol: func_ov004_02156ed0; size: 0x34.
extern "C" void* Menu_FindInventoryGridByKey(void *self, unsigned index) {
    void *context = Menu_GetDisplayRecordRegistry(self);
    void *result = MenuRecordList_LocateByKey(context, index);
    if (!result) return 0;
    if (MenuRecord_GetType(result) != 7) result = 0;
    return result;
}

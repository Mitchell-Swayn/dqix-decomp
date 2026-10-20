#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void MenuBackground_SelectStateRecord(void*, int);
// Original: arm9/ov004 @ 0x021556DC; symbol: func_ov004_021556dc; size: 0x40.
extern "C" int Menu_ClearAlternateCatalogueDetails(void *self) {
    void *context = Menu_GetDisplayRecordRegistry(self);
    void *object = MenuRecordList_LocateByKey(context, 0x2e);
    if (!object) return 0;
    if (MenuRecord_GetType(object) != 0x10) return 0;
    MenuBackground_SelectStateRecord(object, -1);
    return 0;
}

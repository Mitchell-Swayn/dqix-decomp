#include <globaldefs.h>
ARM

extern "C" void *Menu_GetDisplayRecordRegistry(void *self);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
extern "C" void MenuBackground_SelectStateRecord(void *, int);

// Original: arm9/ov004 @ 0x02154210; symbol: func_ov004_02154210; size: 0x40.
extern "C" int Menu_ClearCatalogueDetails(void *self) {
    void *state = Menu_GetDisplayRecordRegistry(self);
    void *object = MenuRecordList_LocateByKey(state, 0x2e);
    if (object == 0) {
        return 0;
    }
    if (MenuRecord_GetType(object) != 0x10) {
        return 0;
    }
    MenuBackground_SelectStateRecord(object, -1);
    return 0;
}

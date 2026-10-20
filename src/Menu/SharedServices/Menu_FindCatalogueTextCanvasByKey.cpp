#include <globaldefs.h>
ARM

extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);

// Original: arm9/ov004 @ 0x02153944; symbol: func_ov004_02153944; size: 0x34.
extern "C" void *Menu_FindCatalogueTextCanvasByKey(void *state, unsigned index) {
    void *resolvedState = Menu_GetDisplayRecordRegistry(state);
    void *object = MenuRecordList_LocateByKey(resolvedState, index);
    if (object == 0) return 0;
    if (MenuRecord_GetType(object) != 6) object = 0;
    return object;
}

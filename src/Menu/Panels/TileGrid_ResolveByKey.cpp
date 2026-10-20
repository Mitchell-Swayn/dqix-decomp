#include <globaldefs.h>
ARM

extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);

// Original: arm9/ov023 @ 0x021F6524; symbol: func_ov023_021f6524; size: 0x34.
extern "C" void *TileGrid_ResolveByKey(void *state, unsigned index) {
    void *resolvedState = Menu_GetDisplayRecordRegistry(state);
    void *object = MenuRecordList_LocateByKey(resolvedState, index);
    if (object == 0) return 0;
    if (MenuRecord_GetType(object) != 7) object = 0;
    return object;
}

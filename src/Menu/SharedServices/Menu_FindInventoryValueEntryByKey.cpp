#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);
// Original: arm9/ov004 @ 0x02156F38; symbol: func_ov004_02156f38; size: 0x34.
extern "C" void *Menu_FindInventoryValueEntryByKey(void *self, unsigned key) {
    void *state = Menu_GetDisplayRecordRegistry(self);
    void *entry = MenuRecordList_LocateByKey(state, key);
    if (entry != 0 && MenuRecord_GetType(entry) == 15) {
        return entry;
    }
    return 0;
}

#include <globaldefs.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
// Original: arm9/ov004 @ 0x02156F04; symbol: func_ov004_02156f04; size: 0x34.
extern "C" void* Menu_FindInventoryTextEntryByKey(State* state, unsigned value) {
    void* head = Menu_GetDisplayRecordRegistry(state);
    void* entry = MenuRecordList_LocateByKey(head, value);
    if (!entry) goto fail;
    if (MenuRecord_GetType(entry) == 8) return entry;
fail:
    return 0;
}

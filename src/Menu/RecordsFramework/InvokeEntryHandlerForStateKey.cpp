#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
// Original: arm9/ov023 @ 0x021F66BC; symbol: func_ov023_021f66bc; size: 0x34.
extern "C" void InvokeEntryHandlerForStateKey(void *self, unsigned key, unsigned value) {
    void *state = Menu_GetDisplayRecordRegistry(self);
    void *entry = MenuRecordList_LocateByKey(state, key);
    if (entry != 0) {
        void **vtable = *(void ***)entry;
        void (*handler)(void *, unsigned) = *(void (**)(void *, unsigned))((unsigned char *)vtable + 0xf0);
        handler(entry, value);
    }
}

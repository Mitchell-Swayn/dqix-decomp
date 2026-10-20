#include <globaldefs.h>
ARM
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
// Original: arm9/ov023 @ 0x021F66F4; symbol: func_ov023_021f66f4; size: 0x34.
extern "C" void MenuRecord_SetNegativeDrawOffsetByKey(void *self, unsigned id, unsigned value) {
    void *context = Menu_GetDisplayRecordRegistry((State *)self);
    void *object = MenuRecordList_LocateByKey(context, id);
    if (object == 0) return;
    void **vtable = *(void ***)object;
    ((void (*)(void *, unsigned))vtable[0xf4 / 4])(object, value);
}

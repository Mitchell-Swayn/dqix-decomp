#include <globaldefs.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State* self);
extern "C" void* MenuRecordList_LocateByKey(void** head, unsigned short value);
extern "C" unsigned MenuRecord_GetType(void* entry);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
extern "C" void MenuTextCanvas_RedrawByKey(State* state, unsigned short value);
// Original: arm9/ov023 @ 0x021F6680; symbol: func_ov023_021f6680; size: 0x3C.
extern "C" void MenuTextCanvas_RedrawByKey(State* state, unsigned short value) {
    void** head = (void**)Menu_GetDisplayRecordRegistry(state);
    void* entry = MenuRecordList_LocateByKey(head, value);
    if (!entry) return;
    if (MenuRecord_GetType(entry) != 6) return;
    MenuTextCanvas_RefreshConfiguredFrameAndContents(entry, state);
}

#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" void MenuBackground_CancelPendingLoads(void *);
// Original: arm9/ov004 @ 0x0216863C; symbol: func_ov004_0216863c; size: 0x34.
extern "C" int Ov004_CheckAndUpdateTypeSeven(void *state) {
    void *object = Menu_GetDisplayRecordRegistry(state);
    object = MenuRecordList_LocateByKey(object, 7);
    if (object != 0 && MenuRecord_GetType(object) == 0x10) {
        MenuBackground_CancelPendingLoads(object);
    }
    return 0;
}

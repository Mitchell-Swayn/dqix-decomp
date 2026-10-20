#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned MenuRecord_GetType(void *);
// Original: arm9/ov004 @ 0x02168AD4; symbol: func_ov004_02168ad4; size: 0x34.
extern "C" void *Ov004_FindObjectWithFieldEleven(void *state, unsigned int type) {
    void *object = MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(state), type);
    if (object != 0 && MenuRecord_GetType(object) == 0x0b) {
        return object;
    }
    return 0;
}

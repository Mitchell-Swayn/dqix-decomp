#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *self);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
// Original: arm9/ov023 @ 0x021F6378; symbol: func_ov023_021f6378; size: 0x34.
extern "C" unsigned int MotionRecord_GetSelectionParameterByKey(State *self, unsigned int id) {
    void *current = Menu_GetDisplayRecordRegistry(self);
    void *result = MenuRecordList_LocateByKey(current, id);
    if (result == 0) return 0;
    unsigned int type = MenuRecord_GetType(result);
    return type != 8 ? 0 : *(unsigned short *)((unsigned char *)result + 0x38);
}

#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" unsigned Menu_GetSelectedGridIndex(unsigned short *);
// Original: arm9/ov004 @ 0x02156E2C; symbol: func_ov004_02156e2c; size: 0x3C.
extern "C" int GetTypeSevenRowMajorIndex(void *self, unsigned key) {
    void *state = Menu_GetDisplayRecordRegistry(self);
    void *entry = MenuRecordList_LocateByKey(state, key);
    if (entry == 0) return -1;
    if (MenuRecord_GetType(entry) == 7)
        return Menu_GetSelectedGridIndex((unsigned short *)entry);
    return -1;
}

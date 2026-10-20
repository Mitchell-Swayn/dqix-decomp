#include <globaldefs.h>
ARM
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
// Original: arm9/ov004 @ 0x02168AA0; symbol: func_ov004_02168aa0; size: 0x34.
extern "C" void *ProfileMenu_FindControlById(void *state, unsigned int key) {
    void *node = MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(state), key);
    if (node != 0 && MenuRecord_GetType(node) == 1) return node;
    return 0;
}

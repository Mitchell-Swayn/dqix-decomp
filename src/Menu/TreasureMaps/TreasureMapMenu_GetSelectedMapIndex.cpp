#include <globaldefs.h>
ARM

extern "C" void *Menu_GetDisplayRecordRegistry(void *self);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned int);
extern "C" unsigned int MenuRecord_GetType(void *);
extern "C" int Menu_GetSelectedGridRow(void *);

// Original: arm9/ov004 @ 0x021634DC; symbol: func_ov004_021634dc; size: 0x40.
extern "C" int TreasureMapMenu_GetSelectedMapIndex(void *self) {
    void *state = Menu_GetDisplayRecordRegistry(self);
    void *object = MenuRecordList_LocateByKey(state, 0xa);
    if (object == 0) {
        return 0;
    }
    if (MenuRecord_GetType(object) != 7) {
        return 0;
    }
    int value = *(short *)((char *)object + 0x5c);
    return Menu_GetSelectedGridRow(object) + (value << 3);
}

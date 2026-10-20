#include <globaldefs.h>
extern "C" void *Menu_GetDisplayRecordRegistry(void *);
extern "C" void *MenuRecordList_LocateByKey(void *, unsigned short);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" void Menu_SetSpriteCellIndex(void *, unsigned short);
// Original: arm9/ov004 @ 0x02165EA4; symbol: func_ov004_02165ea4; size: 0x50.
extern "C" void *Ov004_FindTypeOneAndWriteHalfword(void *state, unsigned short type, unsigned short value) {
    void *object = MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(state), type);
    if (object == 0) object = 0;
    else if (MenuRecord_GetType(object) != 1) object = 0;
    if (object == 0) return 0;
    Menu_SetSpriteCellIndex(object, value);
    return object;
}

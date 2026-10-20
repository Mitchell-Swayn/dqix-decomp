#include <globaldefs.h>
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_SetSelectedGridRow(void*, unsigned short);
extern "C" void Menu_SetSelectedGridColumn(void*, unsigned);
// Original: arm9/ov004 @ 0x02164DF4; symbol: func_ov004_02164df4; size: 0x4C.
extern "C" ARM int TreasureMapMenu_ResetAuxiliaryGridSelection(void* state) {
    void** head = (void**)Menu_GetDisplayRecordRegistry(state);
    void* record = MenuRecordList_LocateByKey(head, 11);
    if (!record) return 0;
    if (MenuRecord_GetType(record) != 7) return 0;
    Menu_SetSelectedGridRow(record, 0);
    Menu_SetSelectedGridColumn(record, 0);
    return 0;
}

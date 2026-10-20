#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_PopulateAlternateCataloguePage(void*);
// Original: arm9/ov004 @ 0x02155544; symbol: func_ov004_02155544; size: 0x6C.
extern "C" int Menu_RefreshAlternateCataloguePageWhenWidgetsExist(void* state) {
    void* head = Menu_GetDisplayRecordRegistry(state);
    void* first = MenuRecordList_LocateByKey((void**)head, 0x2c);
    if (!first)
        return 0;
    if (MenuRecord_GetType(first) != 7)
        return 0;
    void* second = MenuRecordList_LocateByKey((void**)head, 3);
    if (!second)
        return 0;
    if (MenuRecord_GetType(second) != 6)
        return 0;
    Menu_PopulateAlternateCataloguePage(state);
    return 0;
}

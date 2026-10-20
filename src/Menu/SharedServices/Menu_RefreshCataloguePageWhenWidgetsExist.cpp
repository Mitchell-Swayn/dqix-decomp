#include <globaldefs.h>
ARM
#pragma force_active on
// Retain the original entry when callers remain in weak-reference fallback objects.
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Menu_PopulateCataloguePage(void*);
// Original: arm9/ov004 @ 0x02154038; symbol: func_ov004_02154038; size: 0x6c.
// Refreshes the catalogue page only when the expected grid and text records are present.
extern "C" int Menu_RefreshCataloguePageWhenWidgetsExist(void* self)
{
    void* registry = Menu_GetDisplayRecordRegistry(self);
    void* grid = MenuRecordList_LocateByKey((void**)registry, 0x2c);
    if (!grid) return 0;
    if (MenuRecord_GetType(grid) != 7) return 0;
    void* text = MenuRecordList_LocateByKey((void**)registry, 3);
    if (!text) return 0;
    if (MenuRecord_GetType(text) != 6) return 0;
    Menu_PopulateCataloguePage(self);
    return 0;
}

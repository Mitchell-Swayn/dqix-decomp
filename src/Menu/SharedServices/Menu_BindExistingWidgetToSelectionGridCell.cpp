#include <globaldefs.h>
ARM
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *);
extern "C" void *MenuRecordList_LocateByKey(void **, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" int Menu_WriteGridEntry(char *, int, unsigned, unsigned);
#pragma force_active on
// Original: arm9/ov004 @ 0x0216B2C8; symbol: func_ov004_0216b2c8; size: 0x70.
// Binds an existing widget key into row zero of a validated selection-grid column.
extern "C" void Menu_BindExistingWidgetToSelectionGridCell(void *state, int gridKey, int widgetKey, int column)
{
    void *registry = Menu_GetDisplayRecordRegistry((State *)state);
    void *grid = MenuRecordList_LocateByKey((void **)registry, gridKey);
    void *widget = MenuRecordList_LocateByKey((void **)registry, widgetKey);
    if (!grid || !widget) return;
    if (MenuRecord_GetType(grid) != 7) return;
    if (!Menu_WriteGridEntry((char *)grid, (unsigned short)widgetKey, (unsigned short)column, 0)) return;
}

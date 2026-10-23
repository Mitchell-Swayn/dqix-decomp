#include <globaldefs.h>
ARM
struct State;
extern "C" void *Menu_GetDisplayRecordRegistry(State *);
extern "C" void *MenuRecordList_LocateByKey(void **, unsigned);
extern "C" unsigned MenuRecord_GetType(void *);
extern "C" void Menu_SetSelectedGridRow(void *, unsigned);
extern "C" void MenuSelectionGrid_RefreshCursorAndSelectionCallback(void *, void *);
#pragma force_active on
// Original: arm9/ov004 @ 0x0216B338; symbol: func_ov004_0216b338; size: 0x58.
// Selects a row in a validated grid and recomputes cursor position and callbacks.
extern "C" void Menu_SelectGridEntryAndRefreshCursor(void *state, unsigned key, int row)
{
    void *grid = MenuRecordList_LocateByKey((void **)Menu_GetDisplayRecordRegistry((State *)state), key);
    if (!grid) return;
    if (MenuRecord_GetType(grid) != 7) return;
    if (grid) {
        Menu_SetSelectedGridRow(grid, (unsigned short)row);
        MenuSelectionGrid_RefreshCursorAndSelectionCallback(grid, state);
    }
}

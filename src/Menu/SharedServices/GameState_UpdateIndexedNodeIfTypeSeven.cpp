#include <globaldefs.h>
ARM
struct State;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void Menu_SetActiveSelectionGrid(State*, unsigned);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void Memory_ZeroBufferUsingElementCountAndStride(void*);
// Original: arm9/ov004 @ 0x0216B1C4; symbol: func_ov004_0216b1c4; size: 0x48.
extern "C" void GameState_UpdateIndexedNodeIfTypeSeven(State* state, int value) {
    void* list = Menu_GetDisplayRecordRegistry(state);
    void* node = MenuRecordList_LocateByKey((void**)list, value);
    if (!node) return;
    if (MenuRecord_GetType(node) != 7) return;
    Menu_SetActiveSelectionGrid(state, (unsigned short)value);
    Memory_ZeroBufferUsingElementCountAndStride(node);
}

#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_ClearObjectByIndex(void*, unsigned);
extern "C" void* Object_GetGlobalSixteenEntryDisplayState(void);
extern "C" void RemoveMatchingNodeAndResetMatchingObjectSlots(int*, int);
// Original: arm9/ov017 @ 0x021A27E8; symbol: func_ov017_021a27e8; size: 0x58.
extern "C" void GameState_ClearDisplayObjectsAndResetSlots(void) {
    void* state = _ZN9GameState11GetInstanceEv();
    void* display = Object_GetGlobalSixteenEntryDisplayState();
    for (int index = 7; index <= 0x12; ++index)
        GameState_ClearObjectByIndex(state, index);
    for (int key = 0x78; key <= 0x8b; ++key)
        RemoveMatchingNodeAndResetMatchingObjectSlots((int*)display, key);
}

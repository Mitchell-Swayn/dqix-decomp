#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnk4Element0(void*, unsigned);
extern "C" void GameState_WriteUnknownF70(void*, unsigned);
extern "C" void Menu_QueueScriptEntry(void*, unsigned);
// Original: arm9/ov004 @ 0x0216D188; symbol: func_ov004_0216d188; size: 0x3C.
extern "C" int TitleMenu_RequestNewAdventure(void* self) {
    void* state = _ZN9GameState11GetInstanceEv();
    GameState_SetUnk4Element0(state, 2);
    GameState_WriteUnknownF70(state, 0);
    Menu_QueueScriptEntry(self, 999);
    return 0;
}

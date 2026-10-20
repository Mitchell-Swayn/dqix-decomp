#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void GameState_SetUnk4Element0(void *, int);
extern "C" void GameState_WriteUnknownF70(void *, int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216D6DC; symbol: func_ov004_0216d6dc; size: 0x3C.
extern "C" int TitleMenu_RequestAdventureLogUpload(void *object) {
    void *state = _ZN9GameState11GetInstanceEv();
    GameState_SetUnk4Element0(state, 9);
    GameState_WriteUnknownF70(state, 0);
    Menu_QueueScriptEntry(object, 999);
    return 0;
}

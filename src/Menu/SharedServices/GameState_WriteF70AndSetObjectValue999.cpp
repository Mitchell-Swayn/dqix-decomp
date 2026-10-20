#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void GameState_WriteUnknownF70(void *, unsigned int);
extern "C" void Menu_QueueScriptEntry(void *, unsigned int);
// Original: arm9/ov004 @ 0x0216E1E4; symbol: GameState_WriteF70AndSetObjectValue999; size: 0x2C.
// Writes one to GameState field F70, then sends value 0x3E7 to the input object through the state setter.
extern "C" int GameState_WriteF70AndSetObjectValue999(void *p) {
    GameState_WriteUnknownF70(_ZN9GameState11GetInstanceEv(), 1);
    Menu_QueueScriptEntry(p, 0x3e7);
    return 0;
}

#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState14GetProtagonistEv(void* state);
extern "C" unsigned char GameState_GetActionShortcutAssignment(void* object, unsigned index);
// Original: arm9/ov002 @ 0x0215AA5C; symbol: func_ov002_0215aa5c; size: 0x48.
extern "C" void GameState_CopySevenIndexedBytes(void* output) {
    void* protagonist = _ZN9GameState14GetProtagonistEv(_ZN9GameState11GetInstanceEv());
    if (protagonist == 0) return;
    for (int i = 0; i < 7; ++i) {
        *((unsigned char*)output + 0x1C7C + i) = GameState_GetActionShortcutAssignment(protagonist, i);
    }
}

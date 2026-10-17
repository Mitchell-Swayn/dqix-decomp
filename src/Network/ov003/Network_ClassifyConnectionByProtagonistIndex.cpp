#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(GameState*);
extern "C" void *Object_GetGlobalConnectionState();
extern "C" unsigned ReadValue_Main0202BA00(void*);
// Original: arm9/ov003 @ 0x02160B50; symbol: func_ov003_02160b50; size: 0x34.
// Returns zero when connection value is zero, otherwise 1/2 for zero/nonzero protagonist index.
extern "C" int Network_ClassifyConnectionByProtagonistIndex() {
    int result = 0;
    if (ReadValue_Main0202BA00(Object_GetGlobalConnectionState())) {
        if (GameState_ReadProtagonistObjectIndex((GameState*)_ZN9GameState11GetInstanceEv()) == 0) result = 1;
        else result = 2;
    }
    return result;
}

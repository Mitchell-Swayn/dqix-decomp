#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(void *);
extern "C" void *GameState_FindIndexedObjectWithFlag1000(void *, int);
extern "C" int ReadFieldAtOffset2D0(void *);
// Original: arm9/ov000 @ 0x0215FD24; symbol: func_ov000_0215fd24; size: 0x58.
extern "C" int func_ov000_0215fd24(void *unused, int index) {
    void *state = _ZN9GameState11GetInstanceEv();
    int protagonist = GameState_ReadProtagonistObjectIndex(state);
    if (index == protagonist) return 1;
    void *object = GameState_FindIndexedObjectWithFlag1000(state, index);
    return object != 0 && ReadFieldAtOffset2D0(object) == GameState_ReadProtagonistObjectIndex(state);
}

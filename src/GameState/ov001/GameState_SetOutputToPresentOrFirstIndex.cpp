#include <globaldefs.h>
ARM

struct GameResources;
extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" GameResources *GameResources_GetInstance();
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" int GameState_ReadFirstObjectIndex(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov001 @ 0x02161930; symbol: func_ov001_02161930; size: 0x58.
extern "C" int GameState_SetOutputToPresentOrFirstIndex(void *output) {
    void *state = _ZN9GameState11GetInstanceEv();
    unsigned char *resources = (unsigned char *)GameResources_GetInstance();
    unsigned char *object = *(unsigned char **)(resources + 0x3734);
    int index = *(signed char *)(object + 0x116);
    if (GameState_GetObjectWithFlag100(state, index) == 0) {
        index = GameState_ReadFirstObjectIndex(state);
    }
    SetNestedSecondWordForTypeThree(output, index);
    return 1;
}

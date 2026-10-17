#include <globaldefs.h>
ARM

struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadProtagonistObjectIndex(GameState *);
extern "C" void *GameState_GetObjectWithFlag100(void *, int);
extern "C" unsigned char *ReadWordFieldAtOffset150(void *);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);

// Original: arm9/ov023 @ 0x021EA7E0; symbol: func_ov023_021ea7e0; size: 0x74.
extern "C" int GameState_SetTotalProtagonistRecordValue(void *target) {
    void *state = _ZN9GameState11GetInstanceEv();
    void *object = GameState_GetObjectWithFlag100(state, GameState_ReadProtagonistObjectIndex((GameState *)state));
    int sum = 0;
    if (object != 0) {
        unsigned int *values = (unsigned int *)(ReadWordFieldAtOffset150(object) + 0x138);
        for (int i = 0; i < 13; i++) {
            sum += values[i];
            if ((unsigned int)sum > 0x7FFFFFFF) {
                sum = 0x7FFFFFFF;
                break;
            }
        }
    }
    SetNestedSecondWordForTypeThree(target, sum);
    return 1;
}

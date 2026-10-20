#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *GameState_GetIndexList(void *state);
extern "C" void *GameState_GetObjectWithFlag100(void *state, int index);
extern "C" void GameObject_SetUnknownTrackingContext(void *object, int value);

// Original: arm9/ov023 @ 0x021F50FC; symbol: func_ov023_021f50fc; size: 0x54.
extern "C" void BattleResults_SetRosterTrackingContext(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    unsigned char *indices = (unsigned char *)GameState_GetIndexList(state);
    for (int i = 0; i < indices[0xf7c]; i++) {
        unsigned char *entry = indices + i;
        unsigned char id = entry[0xf78];
        void *object = GameState_GetObjectWithFlag100(state, id);
        if (object != 0) GameObject_SetUnknownTrackingContext(object, 2);
    }
}

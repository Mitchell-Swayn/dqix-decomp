#include <globaldefs.h>
ARM
class GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetIndexList(GameState* state);
extern "C" void *Object_GetGlobalConnectionState();
extern "C" int IsFirstWordNonzero(void*);
// Original: arm9/ov023 @ 0x021F4438; symbol: func_ov023_021f4438; size: 0x98.
extern "C" int GameState_HasEnabledConnectionIndex(char *self) {
    int result = 0;
    if (*(unsigned char *)(self + 0x5900) || *(int *)(self + 0x6e24)) {
        GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
        void *connection = Object_GetGlobalConnectionState();
        result = 1;
        if (IsFirstWordNonzero(connection)) {
            unsigned char *indices = (unsigned char *)GameState_GetIndexList(state);
            int found = 0;
            for (int i = 0; i < indices[0xf7c]; ++i) {
                if (*(signed char *)(self + 0x5901) & (1 << *(indices + i + 0xf78))) {
                    found = 1;
                    break;
                }
            }
            if (!found) result = 0;
        }
    }
    return result;
}

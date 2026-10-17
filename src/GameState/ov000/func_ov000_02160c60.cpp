#include <globaldefs.h>
ARM
extern "C" void UpdateTwelveEnabledObjectSlotsAndAngles(void *);
extern "C" ARM void GameState_ProcessTwelveVisibleIndexedObjects(char *);
// Original: arm9/ov000 @ 0x02160C60; symbol: func_ov000_02160c60; size: 0x24.
extern "C" void func_ov000_02160c60(void *p) {
    void *state = *(void **)((unsigned char *)p + 0xea4);
    if (state) {
        UpdateTwelveEnabledObjectSlotsAndAngles(state);
        GameState_ProcessTwelveVisibleIndexedObjects(*(char **)((unsigned char *)p + 0xea4));
    }
}

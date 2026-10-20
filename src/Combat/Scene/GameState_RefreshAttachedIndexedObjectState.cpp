#include <globaldefs.h>
ARM
extern "C" void UpdateTwelveEnabledObjectSlotsAndAngles(void *);
extern "C" ARM void GameState_ProcessTwelveVisibleIndexedObjects(char *);
// Original: arm9/ov000 @ 0x02160C60; symbol: func_ov000_02160c60; size: 0x24.
// If the state pointer at 0xEA4 exists, updates its twelve slots and angles, then processes its visible indexed objects.
extern "C" void GameState_RefreshAttachedIndexedObjectState(void *p) {
    void *state = *(void **)((unsigned char *)p + 0xea4);
    if (state) {
        UpdateTwelveEnabledObjectSlotsAndAngles(state);
        GameState_ProcessTwelveVisibleIndexedObjects(*(char **)((unsigned char *)p + 0xea4));
    }
}

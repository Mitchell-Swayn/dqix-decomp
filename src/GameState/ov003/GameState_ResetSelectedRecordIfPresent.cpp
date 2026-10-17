#include <globaldefs.h>
ARM
struct State;
extern "C" void SetModeByteAndRefreshSelectedRecord(unsigned char *p, unsigned mode);
extern "C" void Object_ResetSelectionAndApplyConfiguredMode(State *p, int flag);
// Original: arm9/ov003 @ 0x0216FF90; symbol: func_ov003_0216ff90; size: 0x2C.
extern "C" void GameState_ResetSelectedRecordIfPresent(void *object) {
    if (*(unsigned int *)((char *)object + 0x3c)) {
        SetModeByteAndRefreshSelectedRecord(*(unsigned char **)((char *)object + 0x3c), 0);
        Object_ResetSelectionAndApplyConfiguredMode((State *)*(unsigned int *)((char *)object + 0x3c), 0);
    }
}

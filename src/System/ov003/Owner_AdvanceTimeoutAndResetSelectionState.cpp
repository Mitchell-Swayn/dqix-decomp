#include <globaldefs.h>
ARM
extern "C" unsigned char *ReadWordFieldAtOffset1C(void);
extern "C" void Resource_InitializeOwnerRecordState(void *, unsigned);
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void *);
// Original: arm9/ov003 @ 0x0217D9D8; symbol: func_ov003_0217d9d8; size: 0x70.
extern "C" void Owner_AdvanceTimeoutAndResetSelectionState(unsigned char *owner) {
    unsigned char *state = ReadWordFieldAtOffset1C();
    signed char phase = *(signed char *)(owner + 5);
    if (phase == 0) {
        Resource_InitializeOwnerRecordState(owner, 0x1869f);
        *(unsigned int *)(state + 0x998) = 1;
        owner[5] = 1;
        return;
    }
    if (phase != 1) return;
    state[0x19ae] = 0;
    if (*(unsigned int *)(state + 0x9a0) != 0) return;
    ResetGlobalOwnerAndEmbeddedSelectionState(state);
    owner[4] = 4;
    owner[5] = 0;
}

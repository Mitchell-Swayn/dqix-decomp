#include <globaldefs.h>
ARM
extern "C" int ItemDetail_DispatchDisplayState(void *);
// Original: arm9/ov002 @ 0x02156178; symbol: func_ov002_02156178; size: 0x38.
extern "C" void GameState_ClearFlagAfterLookup(unsigned char *state) {
    if ((*(unsigned int *)(state + 0x247C) & 1) == 0) goto done;
    if (ItemDetail_DispatchDisplayState(state + 0x50) == 0) goto done;
    *(unsigned int *)(state + 0x247C) &= ~1;
done:
    return;
}

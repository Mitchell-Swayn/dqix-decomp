#include <globaldefs.h>
ARM
// Original: arm9/ov001 @ 0x02159290; symbol: func_ov001_02159290; size: 0xC.
extern "C" void CutsceneCamera_ClearFollowActor(char *p) {
    *(int *)(p + 0xa20) = 0;
}

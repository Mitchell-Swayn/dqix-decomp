#include <globaldefs.h>
ARM
extern "C" unsigned OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[];
// Original: ARM9 arm9/ov031 @ 0x02211AEC; OnlineError_IsSet; size 0x1C.
// Tests the status word also read by OnlineError_GetStatusAndCategory.
extern "C" int OnlineError_IsSet() {
    return OnlineErrorIsSet_UnknownRoleZeroInitializedStorage[0] != 0;
}

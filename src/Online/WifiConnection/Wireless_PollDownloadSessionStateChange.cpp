#include <globaldefs.h>
#pragma optimize_for_size off
ARM
// Original data: arm9/ov031 @ 0x02290d20; symbol: data_ov031_02290d20.
extern "C" unsigned char* Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223AB18; symbol: func_ov031_0223ab18; size: 0x44.
extern "C" void Wireless_PollDownloadSessionStateChange(unsigned char* state, unsigned char* changed) {
    *state = Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90];
    if (Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90] !=
        Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa91]) *changed = 1;
    else *changed = 0;
    Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa91] =
        Ov031AdvanceContextFromFive_UnknownRoleZeroInitializedStorage[0xa90];
}

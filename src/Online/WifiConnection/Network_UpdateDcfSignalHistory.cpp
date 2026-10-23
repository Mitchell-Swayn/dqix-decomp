#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/ov031 @ 0x0224E56C and 0x0224E570.
extern "C" unsigned char NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage;
extern "C" unsigned char NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov031 @ 0x0220F394; symbol: func_ov031_0220f394; size: 0x60.
// Converts a received signal byte and appends it to the sixteen-entry signal history.
extern "C" void Network_UpdateDcfSignalHistory(unsigned char signal) {
    if (signal & 2) signal = signal >> 2;
    else signal = (signal >> 2) + 25;
    int index = NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage;
    NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage_Variant2[index % 16] = signal;
    if ((unsigned)index < 16) {
        NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage = index + 1;
        return;
    }
    NetworkUpdateDcfSignalHistory_UnknownRoleZeroInitializedStorage = ((index + 1) % 16) + 16;
}

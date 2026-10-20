#pragma optimize_for_size off
#include <globaldefs.h>

// Original data: arm9/main @ 0x210f3c0; symbol: data_0210f3c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void SoundCommand_SubmitOpcodeTwentySix(unsigned int mask, int enabled);

// Original: arm9/main @ 0x020BBE1C; symbol: func_020bbe1c; size: 0x48.
extern "C" int Sound_ReserveHardwareChannels(unsigned int mask)
{
    if (mask == 0) {
        return 1;
    }
    if ((mask & SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[2]) != 0) {
        return 0;
    }
    SoundCommand_SubmitOpcodeTwentySix(mask, 0);
    SoundReleaseStreamAlarmSlot_UnknownRoleZeroInitializedStorage[2] |= mask;
    return 1;
}

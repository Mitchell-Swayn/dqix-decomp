#include <globaldefs.h>
ARM
extern "C" void Sound_UpdatePlaybackAndFlushCommands();

// Original: arm9/ov031 @ 0x02236900; symbol: func_ov031_02236900; size: 0xC.
extern "C" void WfcUtility_UpdateSoundPlaybackTask(void) {
    Sound_UpdatePlaybackAndFlushCommands();
}

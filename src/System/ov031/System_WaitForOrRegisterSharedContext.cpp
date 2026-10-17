#include <globaldefs.h>
ARM
extern "C" unsigned _Z16GetProcessorModev(void);
extern "C" void _Z19SleepCurrentContextj(unsigned);
extern "C" void* data_ov031_0224c9d0;
extern "C" unsigned data_ov031_0224e1c8;
extern "C" void* data_ov031_0224e1c4;
// Original: arm9/ov031 @ 0x02206F3C; symbol: func_ov031_02206f3c; size: 0x68.
extern "C" void* System_WaitForOrRegisterSharedContext(void) {
    void* context = data_ov031_0224c9d0;
    if (!context) {
        if ((data_ov031_0224e1c8 & 3) == 1 && _Z16GetProcessorModev() != 0x12)
            _Z19SleepCurrentContextj(10);
    } else if (!data_ov031_0224e1c4) {
        data_ov031_0224e1c4 = context;
    }
    return data_ov031_0224c9d0;
}

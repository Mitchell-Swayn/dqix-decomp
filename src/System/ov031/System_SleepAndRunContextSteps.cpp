#include <globaldefs.h>
ARM
extern "C" void _Z19SleepCurrentContextj(unsigned ticks);
extern "C" void func_ov031_02231468(void);
extern "C" void func_ov031_022312a4(void);
extern "C" void func_ov031_022312dc(void);
extern "C" void System_InstallCallbackIfSharedByteIsZero(void);
// Original: arm9/ov031 @ 0x02231284; symbol: func_ov031_02231284; size: 0x20.
extern "C" void System_SleepAndRunContextSteps(void) {
    _Z19SleepCurrentContextj(10);
    func_ov031_02231468();
    func_ov031_022312a4();
    func_ov031_022312dc();
    System_InstallCallbackIfSharedByteIsZero();
}

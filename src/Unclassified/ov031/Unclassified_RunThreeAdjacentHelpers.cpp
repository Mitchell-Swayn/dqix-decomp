#include <globaldefs.h>
ARM
extern "C" void func_ov031_0222938c(void);
extern "C" void func_ov031_02229480(void);
extern "C" void System_SelectSharedStateAndInstallCallback(void);
// Original: arm9/ov031 @ 0x02229378; symbol: func_ov031_02229378; size: 0x14.
extern "C" void Unclassified_RunThreeAdjacentHelpers(void) {
    func_ov031_0222938c();
    func_ov031_02229480();
    System_SelectSharedStateAndInstallCallback();
}

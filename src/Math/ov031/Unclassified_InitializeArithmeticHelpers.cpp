#include <globaldefs.h>
ARM
extern "C" void OV031_ProcessBlockedContextCommand();
extern "C" void System_CancelAndRestartStateNineAlarm();
// Original: arm9/ov031 @ 0x0220DB28; symbol: func_ov031_0220db28; size: 0x10.
extern "C" void Unclassified_InitializeArithmeticHelpers(void) {
    OV031_ProcessBlockedContextCommand();
    System_CancelAndRestartStateNineAlarm();
}

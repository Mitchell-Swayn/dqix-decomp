#include <globaldefs.h>
ARM
extern "C" unsigned PowerManagement_SendCommandEighteenSynchronously(unsigned value);
// Original: arm9/ov031 @ 0x0223DFFC; symbol: func_ov031_0223dffc; size: 0x10.
extern "C" unsigned WfcUtility_SendPowerManagementOperationEighteenOne(void) { return PowerManagement_SendCommandEighteenSynchronously(1); }

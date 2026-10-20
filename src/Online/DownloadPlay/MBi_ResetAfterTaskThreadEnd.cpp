#include <globaldefs.h>
ARM
extern "C" void MBi_CallReset(void);
// Original: arm9/ov027 @ 0x021DCC80; symbol: func_ov027_021dcc80; size: 0xC.
extern "C" void MBi_ResetAfterTaskThreadEnd(void) {
    MBi_CallReset();
}

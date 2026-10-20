#include <globaldefs.h>
ARM
extern "C" unsigned GetPendingOverlayDataIfReady(void);
// Original: arm9/ov031 @ 0x02205018; symbol: func_ov031_02205018; size: 0x18.
extern "C" unsigned Network_IsSharedReceiveDataReady(void) {
    return GetPendingOverlayDataIfReady() != 0;
}

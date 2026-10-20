#include <globaldefs.h>
ARM
extern "C" void Overlay_RemoveIndexedPointerPair(void);
// Original: arm9/ov031 @ 0x0223E2E0; symbol: func_ov031_0223e2e0; size: 0xC.
extern "C" void WfcUtility_RemoveTaskImmediately(void) { Overlay_RemoveIndexedPointerPair(); }

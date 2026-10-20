#include <globaldefs.h>
ARM
extern "C" void Network_CleanupSocketStack();
// Original: arm9/ov031 @ 0x022077C0; symbol: func_ov031_022077c0; size: 0xC.
extern "C" void System_DrainSharedSequenceAndReleaseContext(void) {
    Network_CleanupSocketStack();
}

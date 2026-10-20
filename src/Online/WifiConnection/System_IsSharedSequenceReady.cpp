#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x22496a4; symbol: data_ov031_022496a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NetworkCleanupSocketStack_UnknownRoleInitializedBytes;
extern "C" int System_PollSharedSequenceAndDrainQueue();
extern "C" int System_DrainSharedSequenceAndReleaseContext();
// Original: arm9/ov031 @ 0x022142EC; symbol: func_ov031_022142ec; size: 0x48.
extern "C" int System_IsSharedSequenceReady(void) {
    if (NetworkCleanupSocketStack_UnknownRoleInitializedBytes == 0) return 1;
    if (System_PollSharedSequenceAndDrainQueue() != 0) return 0;
    int status = System_DrainSharedSequenceAndReleaseContext();
    return status == 0 || status == -39;
}

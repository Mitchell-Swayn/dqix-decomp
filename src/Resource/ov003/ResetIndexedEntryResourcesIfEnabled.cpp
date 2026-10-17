#include <globaldefs.h>
ARM
extern "C" void ResetEachIndexedEntryResource(void *);
// Original: arm9/ov003 @ 0x021685A8; symbol: func_ov003_021685a8; size: 0x1C.
extern "C" void ResetIndexedEntryResourcesIfEnabled(void *object) {
    if (*(unsigned char *)((char *)object + 0x4ec) != 0)
        ResetEachIndexedEntryResource((char *)object + 0xe4);
}

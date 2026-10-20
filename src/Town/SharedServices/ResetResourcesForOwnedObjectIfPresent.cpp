#include <globaldefs.h>
ARM
extern "C" void ResetIndexedEntryResourcesIfEnabled(void *);
// Original: arm9/ov003 @ 0x0217E598; symbol: func_ov003_0217e598; size: 0x18.
extern "C" void ResetResourcesForOwnedObjectIfPresent(void *owner) {
    void *object = *(void **)((char *)owner + 0x20);
    if (object)
        ResetIndexedEntryResourcesIfEnabled(object);
}

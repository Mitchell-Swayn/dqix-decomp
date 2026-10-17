#include <globaldefs.h>

extern "C" void InitializeObjectHandlesAndInvalidIndices(void*);
extern "C" void CleanupPointedResourceAndResetOwner(void*);

// Original: arm9/main @ 0x0209C278; symbol: func_0209c278; size: 0x18.
extern "C" ARM void ResetObjectStateAndReleaseLinkedResource(void* object) {
    InitializeObjectHandlesAndInvalidIndices(object);
    CleanupPointedResourceAndResetOwner(object);
}

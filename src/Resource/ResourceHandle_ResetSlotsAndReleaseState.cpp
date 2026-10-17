#include <globaldefs.h>

extern "C" void TransferActiveResourceHandleAndInvalidateIndices(void*);
extern "C" void CleanupPointedResourceAndResetOwner(void*);

// Original: arm9/main @ 0x0205E92C; symbol: func_0205e92c; size: 0x18.
extern "C" ARM void ResourceHandle_ResetSlotsAndReleaseState(void* object) {
    TransferActiveResourceHandleAndInvalidateIndices(object);
    CleanupPointedResourceAndResetOwner(object);
}

#include <globaldefs.h>

extern "C" void CleanupPointedResourceAndResetOwner(void*);
extern "C" void ResourceHandle_InitializeThreeValueIndexSlots(void*);

// Original: arm9/main @ 0x0205E8D4; symbol: func_0205e8d4; size: 0x18.
extern "C" ARM void UpdateObjectThroughTwoHandlers(void* object) {
    CleanupPointedResourceAndResetOwner(object);
    ResourceHandle_InitializeThreeValueIndexSlots(object);
}

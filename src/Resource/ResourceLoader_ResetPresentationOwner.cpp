#include <globaldefs.h>
extern "C" void BackgroundLoader_RemoveTaskAndClearLoadedPointer(void);
extern "C" void ResourceLoader_UnregisterPresentationOrCancelLoad(int);
extern "C" void ResourceLoader_InitializePresentationOwner(int);

// Original: arm9/main @ 0x020DBEBC; symbol: func_020dbebc; size: 0x20.
extern "C" void ResourceLoader_ResetPresentationOwner(int object) {
    BackgroundLoader_RemoveTaskAndClearLoadedPointer();
    ResourceLoader_UnregisterPresentationOrCancelLoad(object);
    ResourceLoader_InitializePresentationOwner(object);
}

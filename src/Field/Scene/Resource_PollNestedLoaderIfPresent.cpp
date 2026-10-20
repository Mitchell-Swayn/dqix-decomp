#include <globaldefs.h>
ARM
extern "C" void ResourceLoader_PollTaskCopyAndRegisterLoadedFile(void *owner);
// Original: arm9/ov017 @ 0x0218D5AC; symbol: func_ov017_0218d5ac; size: 0x1C.
extern "C" void Resource_PollNestedLoaderIfPresent(void *object) {
    void *owner = *(void **)((char *)object + 0x4498);
    if (owner)
        ResourceLoader_PollTaskCopyAndRegisterLoadedFile(owner);
}

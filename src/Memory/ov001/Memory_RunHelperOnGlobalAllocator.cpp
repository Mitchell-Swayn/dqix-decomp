#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov001_021658b8[];
extern "C" void Resource_AllocateOverlayScriptObjectBuffers(void *);
// Original: arm9/ov001 @ 0x0215F2E8; symbol: func_ov001_0215f2e8; size: 0x1C.
extern "C" unsigned int Memory_RunHelperOnGlobalAllocator(void) {
    Resource_AllocateOverlayScriptObjectBuffers(*(void **)data_ov001_021658b8);
    return 1;
}

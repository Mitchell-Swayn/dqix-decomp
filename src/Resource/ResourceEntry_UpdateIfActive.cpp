#include <globaldefs.h>

extern "C" void ResourceEntry_StopRegisteredChannelAndCleanup(void*);
struct Owner { char unknown[0x24]; signed int active:1; };

// Original: arm9/main @ 0x020BCBC4; symbol: func_020bcbc4; size: 0x1C.
extern "C" ARM void ResourceEntry_UpdateIfActive(Owner* object) {
    if (object->active) ResourceEntry_StopRegisteredChannelAndCleanup(object);
}

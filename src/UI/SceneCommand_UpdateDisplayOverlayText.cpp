#include <globaldefs.h>

extern "C" void Town_RenderDestinationMenuText(void*);
struct Owner { char unknown[12]; void* handle; };

// Original: arm9/main @ 0x020DAE80; symbol: func_020dae80; size: 0x18.
extern "C" ARM void SceneCommand_UpdateDisplayOverlayText(Owner* object) {
    if(object->handle) Town_RenderDestinationMenuText(object->handle);
}

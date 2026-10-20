#include <globaldefs.h>

extern "C" void Object_ClearAndResetOptionalResourceHandle(void*);
struct Owner { char unknown[12]; void* handle; };

// Original: arm9/main @ 0x020DAE68; symbol: func_020dae68; size: 0x18.
extern "C" ARM void SceneCommand_ResetDisplayOverlayResources(Owner* object) {
    if(object->handle) Object_ClearAndResetOptionalResourceHandle(object->handle);
}

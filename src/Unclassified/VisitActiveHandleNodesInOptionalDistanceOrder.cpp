#include <globaldefs.h>

extern "C" void DrawActiveEffectsInOptionalDistanceOrder(void*);
struct HandleOwner { char unknown[0x4]; void* handle; };

// Original: arm9/main @ 0x0205578C; symbol: func_0205578c; size: 0x18.
extern "C" ARM void VisitActiveHandleNodesInOptionalDistanceOrder(HandleOwner* owner) {
    if (owner->handle)
        DrawActiveEffectsInOptionalDistanceOrder(owner->handle);
}

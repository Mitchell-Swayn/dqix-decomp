#include <globaldefs.h>

extern "C" void SetAngleAndCacheTrig(void*, unsigned);
struct Owner { char unknown[0x1f0]; unsigned angle; int pending; };

// Original: arm9/main @ 0x0202F0C4; symbol: func_0202f0c4; size: 0x1C.
extern "C" ARM void Object_SetAngleAndDeferredUpdateFlag(Owner* object, unsigned angle, int pending) {
    object->angle=angle;
    object->pending=pending;
    if (!pending) SetAngleAndCacheTrig(object, angle);
}

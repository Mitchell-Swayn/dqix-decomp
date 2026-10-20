#include <globaldefs.h>

extern "C" void Object3D_UpdateVisibilityAndAlphaByKind(void*);
struct Owner { char unknown[0xbe]; unsigned char current; unsigned char previous; };

// Original: arm9/main @ 0x02033B68; symbol: func_02033b68; size: 0x20.
extern "C" ARM void GameObject_ChangeMotionStateAndRefreshAnimation(Owner* object, unsigned value) {
    if(object->current==value) return;
    object->previous=object->current;
    object->current=value;
    Object3D_UpdateVisibilityAndAlphaByKind(object);
}

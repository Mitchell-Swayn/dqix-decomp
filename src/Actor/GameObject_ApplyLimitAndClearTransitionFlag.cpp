#include <globaldefs.h>

extern "C" void GameObject_ReviveAndRestoreHP(void*, int, int, void*);
struct Owner { char unknown[0x18c]; unsigned flags; };

// Original: arm9/main @ 0x02053FE4; symbol: func_02053fe4; size: 0x1C.
extern "C" ARM void GameObject_ApplyLimitAndClearTransitionFlag(Owner* object, int limit, int notify, void* context) {
    GameObject_ReviveAndRestoreHP(object, limit, notify, context);
    object->flags &= ~1u;
}

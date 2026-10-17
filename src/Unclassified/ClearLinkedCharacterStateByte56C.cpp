#include <globaldefs.h>

extern "C" void ClearField56CAndOptionallyNotifyHandlers(void*);
struct HandleOwner { char unknown[0x150]; void* handle; };

// Original: arm9/main @ 0x0205420C; symbol: func_0205420c; size: 0x18.
extern "C" ARM void ClearLinkedCharacterStateByte56C(HandleOwner* owner) {
    if (owner->handle)
        ClearField56CAndOptionallyNotifyHandlers(owner->handle);
}

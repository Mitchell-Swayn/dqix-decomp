#include <globaldefs.h>

extern "C" void CharacterState_ClearEncounterSuppression(void*);
struct HandleOwner { char unknown[0x150]; void* handle; };

// Original: arm9/main @ 0x0205420C; symbol: func_0205420c; size: 0x18.
extern "C" ARM void GameObject_ClearLinkedCharacterStateAndNotify(HandleOwner* owner) {
    if (owner->handle)
        CharacterState_ClearEncounterSuppression(owner->handle);
}

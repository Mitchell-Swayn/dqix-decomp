#include "TextOwner.h"
#include "GameState/GameState.h"

typedef void (TextOwner::*TextStateCallback)();
struct TextStateCallbacks { TextStateCallback entries[13]; };
extern "C" {
void func_020a20d8(void*);
void* func_0205d8c4(void*);
int func_0204c7cc(void*);
void func_0205bc24(void*, int);
int func_0205d0e0(void*, unsigned int);
void func_ov023_021e5020(void*);
void func_ov009_02188604(TextOwner*, unsigned int);
void func_ov009_02188454(TextOwner*);
void func_ov009_021885b8(TextOwner*);
void func_ov009_02184d70(TextOwner*);
extern const TextStateCallbacks data_ov009_0218ab9c;
extern const TextStateCallback data_020e6d5c;
}

extern "C" int func_ov009_02184a18(TextOwner* owner)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (!ticks) ticks = 1;
    if (owner->state) func_020a20d8(owner->unknown_924);
    if (owner->state == 9 && owner->substate == 2) {
        unsigned char* active = (unsigned char*)func_0205d8c4(owner->controllers[1]);
        if (active && func_0204c7cc(active) && !(active[0xc5] & 2))
            func_0205bc24(owner->controllers[1] + 4, -1);
    }
    func_0205d0e0(owner->controllers[0], ticks);
    owner->controllerResult = func_0205d0e0(owner->controllers[1], ticks);
    if (owner->flags & 0x200) {
        owner->objectA.AdvanceEffects();
        owner->objectB.AdvanceEffects();
    }
    if (owner->handles[2]) func_ov023_021e5020(owner->handles[2]);
    if (owner->handles[3]) func_ov023_021e5020(owner->handles[3]);
    func_ov009_02188604(owner, ticks);
    func_ov009_02188454(owner);
    func_ov009_021885b8(owner);
    // Preserve the member-pointer representation, including possible virtual
    // dispatch and this adjustment. The final state is the null callback.
    TextStateCallbacks callbacks = data_ov009_0218ab9c;
    callbacks.entries[12] = data_020e6d5c;
    if (!callbacks.entries[owner->state]) return 0;
    (owner->*callbacks.entries[owner->state])();
    func_ov009_02184d70(owner);
    return owner->state == 12;
}

#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void*, short, int);
// Original: arm9/ov017 @ 0x021C98F4; symbol: func_ov017_021c98f4; size: 0x60.
extern "C" void UpdateFourMatchingObjectHalfwords(int target, int force) {
    void* game = _ZN9GameState11GetInstanceEv();
    for (int index = 0; index < 4; ++index) {
        void* object = GameState_GetObjectWithFlag100(game, index);
        if (object && target == *(unsigned short*)((char*)object + 0x1b2))
            Object_SetHalfword1B2WhenMemberListedOrForced(object, 0, force);
    }
}

#include <globaldefs.h>
ARM
extern "C" void func_ov015_0218c538(void*, int);
extern "C" void Resource_ReloadObjectGroupAnimationFromGPC(void*, int);
struct AnimationState { unsigned char pad[0x1c]; unsigned char type; unsigned char pad2[0x2b]; int frame; };
// Original: arm9/ov015 @ 0x02190090; symbol: func_ov015_02190090; size: 0x4C.
extern "C" void AdvanceAnimationForType(AnimationState* state) {
    state->frame = ++state->frame % 2;
    switch (state->type) {
    case 0: func_ov015_0218c538(state, 0); break;
    case 1: Resource_ReloadObjectGroupAnimationFromGPC(state, 0); break;
    }
}

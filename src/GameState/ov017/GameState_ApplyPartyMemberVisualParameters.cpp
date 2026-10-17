#include <globaldefs.h>
ARM
struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(void*, int);
extern "C" void SetMaskedFlagsAtOffset1CE(int);
// Original: arm9/ov017 @ 0x021D2C78; symbol: func_ov017_021d2c78; size: 0x48.
extern "C" void GameState_ApplyPartyMemberVisualParameters(void*, unsigned char* data) {
    void* state = _ZN9GameState11GetInstanceEv();
    Object3D* member = _ZN9GameState21GetPartyMemberByIndexEi(state, data[4]);
    if (!member) return;
    _ZN8Object3D17SetInheritedAlphaEi(member, data[5]);
    if (data[5] != 0 || data[6] == 0) return;
    SetMaskedFlagsAtOffset1CE((int)member);
}

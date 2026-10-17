#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void Object_SetUnsignedCharAtOffset1CEMask10(int self);
extern "C" void SetResolvedSlotBitAt100F(char *p, int key);
// Original: arm9/ov017 @ 0x021CEAB4; symbol: func_ov017_021ceab4; size: 0x30.
extern "C" void Ov017_ResolvePartyMemberSlot(int index, int unused1, int unused2, int unused3, char *resolvedBits) {
    void *member;
    member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (member) Object_SetUnsignedCharAtOffset1CEMask10((int)member);
    SetResolvedSlotBitAt100F(resolvedBits, index);
}

#include <globaldefs.h>
ARM
extern "C" int _Z16GetCombatantByIDii(int, int);
extern "C" int TestLinkedDescriptorFlag8(void*);
extern "C" unsigned short SelectHalfwordForPartyIndex(int, int, int);
// Original: arm9/ov024 @ 0x021E9464; symbol: func_ov024_021e9464; size: 0x60.
extern "C" int Combatant_GetPartyStateValue(void* record, int partyIndex, int mode) {
    int combatant = _Z16GetCombatantByIDii(*(int*)((char*)record + 0x10), partyIndex);
    if (!combatant) return 0;
    int flag = TestLinkedDescriptorFlag8((void*)combatant);
    if (mode) return flag ? 0x6e : 0x1e;
    if (flag) return 0x6f;
    return SelectHalfwordForPartyIndex(partyIndex, 0x26d, 0x1b);
}

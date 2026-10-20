#include <globaldefs.h>
ARM
extern "C" void* GameState_FindIndexedObjectWithFlag1000(void*, int);
extern "C" void GameObject_SetAssociatedPartyMemberIndex(void*, signed char);
extern "C" void GameObject_SetSecondaryPartyMemberIndex(void*, signed char);
extern "C" void GameObject_SetFollowPredecessorMember(void*, signed char);
extern "C" void GameObject_SetPartyFormationOrder(void*, signed char);
// Original: arm9/ov017 @ 0x021CE3AC; symbol: func_ov017_021ce3ac; size: 0x54.
extern "C" void Field_ApplyObjectPartyFormation(unsigned unused, unsigned char* record, void* state) {
    void* object = GameState_FindIndexedObjectWithFlag1000(state, *(unsigned short*)(record + 4));
    if (object == 0) return;
    GameObject_SetAssociatedPartyMemberIndex(object, (signed char)record[6]);
    GameObject_SetSecondaryPartyMemberIndex(object, (signed char)record[7]);
    GameObject_SetFollowPredecessorMember(object, (signed char)record[8]);
    GameObject_SetPartyFormationOrder(object, (signed char)record[9]);
    *(unsigned char*)((char*)object + 0x2d2) = (unsigned char)record[0xa];
}

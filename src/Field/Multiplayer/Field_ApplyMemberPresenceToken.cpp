#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *state, int index);
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void *record, int value, int force);
// Original: arm9/ov017 @ 0x021CBEEC; symbol: GameState_ApplyRecordHalfwordToPartyMember; size: 0x2C.
// Finds the party member using signed record byte +4, then applies unsigned halfword +6 with force enabled.
extern "C" void Field_ApplyMemberPresenceToken(void *unused, char *record, void *state) {
    int index = *(signed char *)(record + 4);
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(state, index);
    if (member)
        Object_SetHalfword1B2WhenMemberListedOrForced(member, *(unsigned short *)(record + 6), 1);
}

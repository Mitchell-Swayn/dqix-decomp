#include <globaldefs.h>
extern "C" void Field_RemovePartyMemberAndEquipment(void *, int);
extern "C" int Network_GetLocalMemberId(char *);
// Original: arm9/ov017 @ 0x021CC6C4; symbol: func_ov017_021cc6c4; size: 0x6C.
extern "C" void PartySync_ApplyRemovedMemberList(void *unused, unsigned char *entries, void *unused2, void *owner, char *record) {
    int hasEmpty = 0;
    for (int i = 0; i < entries[4]; ++i) {
        unsigned char *entry = entries + i;
        unsigned char item = entry[5];
        Field_RemovePartyMemberAndEquipment(owner, item);
        if (item == 0) hasEmpty = 1;
    }
    if (hasEmpty && Network_GetLocalMemberId(record)) *((unsigned char *)owner + 0x42e1) = 1;
}

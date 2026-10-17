#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
extern "C" void *GetEntryFromBiasedSignedIndex1E4(void *);

// Original: arm9/ov003 @ 0x02155F40; symbol: func_ov003_02155f40; size: 0x48.
extern "C" int GameState_PartyMemberHasMatchingIndexedEntry(void *entryContext, int partyIndex) {
    void *gameState = _ZN9GameState11GetInstanceEv();
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(gameState, partyIndex);
    if (member == 0) goto missing;
    void *entry = *(void **)(*(char **)((char *)member + 0x150) + 0x950);
    return entry == GetEntryFromBiasedSignedIndex1E4(entryContext);
missing:
    return 0;
}

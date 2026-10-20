#include <globaldefs.h>
ARM

extern "C" void *_ZN9GameState11GetInstanceEv();
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *state, int index);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *object);
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(unsigned char *records, int key);

// Original: arm9/ov003 @ 0x0217A220; symbol: func_ov003_0217a220; size: 0x60.
extern "C" void GameState_StorePartyGroupTableHalfword(unsigned char *state) {
    short result = -1;
    void *gameState = _ZN9GameState11GetInstanceEv();
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(gameState, *(signed char *)(state + 0x1043));
    if (member != 0) {
        unsigned char *table = GameObject_GetLinkedIndexedState(member);
        int count = FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(*(unsigned char **)(state + 0x89c), 0x15);
        int difference = *(short *)(state + 0x100e) - count;
        result = *(short *)(table + ((short)difference << 1) + 0x454);
    }
    *(short *)(state + 0x103a) = result;
}

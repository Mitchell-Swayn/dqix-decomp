#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* GameState_GetIndexList(void* state);
extern "C" int GameState_TestKeyInContainersOrListedPartyMembers(unsigned char* p, int key);
// Original: arm9/ov004 @ 0x02167A0C; symbol: func_ov004_02167a0c; size: 0x60.
extern "C" int GameState_ApplyPartyKeySideEffectsAndIncrementCount(void* unused, int amount) {
    void* state = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    unsigned char* list = (unsigned char*)state;
    for (int i = 0; i < amount; i++)
        GameState_TestKeyInContainersOrListedPartyMembers(list, 0x5617);
    int value = (short)(*(int*)((char*)state + 0xf74) + amount);
    if (value > 500)
        value = 500;
    *(int*)((char*)state + 0xf74) = value;
    return 0;
}

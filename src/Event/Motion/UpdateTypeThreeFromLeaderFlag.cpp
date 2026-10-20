#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
extern "C" unsigned char *GameObject_GetLinkedIndexedState(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x02162D68; symbol: func_ov001_02162d68; size: 0x48.
extern "C" int UpdateTypeThreeFromLeaderFlag(void *object) {
    void *leader = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), 0);
    if (leader == 0) return 0;
    unsigned bit = (unsigned)GameObject_GetLinkedIndexedState(leader)[0x49c] << 31;
    bit >>= 31;
    Script_WriteIntegerReferenceOutput(object, bit == 0);
    return 1;
}

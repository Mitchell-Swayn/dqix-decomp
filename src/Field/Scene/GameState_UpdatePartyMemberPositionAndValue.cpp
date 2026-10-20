#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
struct Vector3 { int x, y, z; };
extern "C" Vector3 *_ZN8Vector3iaSERKS_(Vector3 *, const Vector3 *);
// Original: arm9/ov017 @ 0x021BD3D4; symbol: func_ov017_021bd3d4; size: 0x6C.
extern "C" void GameState_UpdatePartyMemberPositionAndValue(void *state, int index) {
    unsigned int mask = (1 << index) & 0xff;
    *((unsigned char *)state + 0x174) |= mask;
    *((unsigned char *)state + 0x175) &= ~mask;
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (member == 0) return;
    _ZN8Vector3iaSERKS_((Vector3 *)((char *)state + 0x188 + index * 12), (Vector3 *)((char *)member + 0x44));
    *(unsigned int *)((char *)state + 0x1b8 + index * 4) = *(unsigned int *)((char *)member + 0x54);
}

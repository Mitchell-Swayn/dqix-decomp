#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState21GetPartyMemberByIndexEi(void *, int);
// Original: arm9/ov003 @ 0x02155F88; symbol: func_ov003_02155f88; size: 0x38.
extern "C" unsigned int Alltrades_IsMemberCursedOrMissing(int ignored, int index) {
    void *member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    int result = 1;
    if (member != 0) {
        void *state = *(void **)((unsigned char *)member + 0x130);
        if ((*(unsigned int *)state & 4) == 0) result = 0;
    }
    return result;
}

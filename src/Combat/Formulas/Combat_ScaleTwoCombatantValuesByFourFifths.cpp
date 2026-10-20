#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
// Original: arm9/ov024 @ 0x021D923C; symbol: func_ov024_021d923c; size: 0x94.
extern "C" int Combat_ScaleTwoCombatantValuesByFourFifths(char **self, int sourceIndex, int targetIndex, int unused, int unused2, int fallback) {
    void *state = _ZN9GameState11GetInstanceEv();
    char *source = _ZN9GameState19GetCombatantByIndexEi(state, sourceIndex);
    char *target = _ZN9GameState19GetCombatantByIndexEi(state, targetIndex);
    if (!source || !target) return fallback;
    int value = (int)(0.8f * (float)(unsigned int)**(unsigned short**)(source + 0x138));
    *(int*)(*self + 0x8e38) = value + 2;
    return (int)(0.8f * (float)(unsigned int)**(unsigned short**)(target + 0x138));
}

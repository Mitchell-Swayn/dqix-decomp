#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*, float, float);
// Original: arm9/ov024 @ 0x021D937C; symbol: func_ov024_021d937c; size: 0x60.
extern "C" int Combat_ComputeRandomFractionOfCombatantValue(void** random, int index, unsigned unused1, unsigned unused2, unsigned unused3, int fallback) {
    void* combatant = _ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (combatant == 0) return fallback;
    unsigned value = *(unsigned short*)((char*)*(void**)((char*)combatant + 0x138) + 4);
    float factor = _Z22NextRandomFloatBetweenP6Randomff(*random, 0.4f, 0.6f);
    return (int)((float)value * factor);
}

#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*, float, float);
// Original: arm9/ov024 @ 0x021D931C; symbol: func_ov024_021d931c; size: 0x60.
extern "C" int Combat_GetRandomizedCombatantStatWithFallback(void** owner, int index, int a, int b, int c, int fallback) {
    char* combatant = (char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (combatant == 0) return fallback;
    unsigned value = *(unsigned short*)(*(char**)(combatant + 0x138) + 4);
    float factor = _Z22NextRandomFloatBetweenP6Randomff(*owner, 0.2f, 0.3f);
    return (int)((float)value * factor);
}

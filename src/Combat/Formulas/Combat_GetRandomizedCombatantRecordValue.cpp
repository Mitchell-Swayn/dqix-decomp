#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" float _Z22NextRandomFloatBetweenP6Randomff(void*, float, float);
// Original: arm9/ov024 @ 0x021D8B68; symbol: Combat_GetRandomizedCombatantRecordValue; size: 0x60.
// Gets a combatant by index, returns fallback if absent, otherwise scales its halfword value by a random factor from 0.85 to 0.95.
extern "C" int Combat_GetRandomizedCombatantRecordValue(void** random, int index, int a, int b, int c, int fallback) {
    char* combatant = (char*)_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (!combatant) return fallback;
    void* rng = *random;
    unsigned int value = *(unsigned short*)(*(char**)(combatant + 0x134) + 0x34);
    float factor = _Z22NextRandomFloatBetweenP6Randomff(rng, 0.85f, 0.95f);
    return (int)((float)value * factor);
}

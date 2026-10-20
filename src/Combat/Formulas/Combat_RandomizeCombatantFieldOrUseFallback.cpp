#include <globaldefs.h>
ARM
extern "C" void* _Z16GetCombatantByIDii(void*, int);
extern "C" unsigned int _Z22NextRandomFloatBetweenP6Randomff(void*, float, float);
extern "C" unsigned int _ffltu(unsigned int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D974C; symbol: Combat_RandomizeCombatantFieldOrUseFallback; size: 0x5C.
// Looks up the signed combatant id; returns fallback if absent, otherwise scales its nested halfword by a random float from 0.2 to 0.5 and converts to fixed point.
extern "C" int Combat_RandomizeCombatantFieldOrUseFallback(void* self, int id, int unused1, int unused2, int unused3, int fallback) {
    void* combatant = _Z16GetCombatantByIDii(*(void**)self, (short)id);
    if (combatant == 0) return fallback;
    unsigned short value = *(unsigned short*)(*(char**)((char*)combatant + 0x138) + 6);
    unsigned int random = _Z22NextRandomFloatBetweenP6Randomff(*(void**)self, 0.2f, 0.5f);
    return _ffix(_fmul(_ffltu(value), random));
}

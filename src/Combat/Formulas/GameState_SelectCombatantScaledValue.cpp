#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" int _Z13NextRandomMaxP6Randomi(void*, int);
extern "C" unsigned _ffltu(unsigned);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(unsigned);
// Original: arm9/ov024 @ 0x021D95E0; symbol: func_ov024_021d95e0; size: 0x74.
extern "C" int GameState_SelectCombatantScaledValue(void* randomContext, int unused, int combatantIndex, int unused2, int unused3, int output) {
    void* combatant = _ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), combatantIndex);
    if (combatant == 0) return output;
    if (_Z13NextRandomMaxP6Randomi(*(void**)randomContext, 2) > 0) {
        *(unsigned char*)((char*)*(void**)randomContext + 0x8e94) = 1;
        return 0x10000 - 1;
    }
    unsigned short value = **(unsigned short**)((char*)combatant + 0x138);
    return _ffix(_fmul(0x3f7d70a4, _ffltu(value)));
}

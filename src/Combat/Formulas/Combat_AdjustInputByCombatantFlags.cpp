#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" bool CombatStatus_HasSleep(unsigned*);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix();
// Original: arm9/ov024 @ 0x021D8DB4; symbol: func_ov024_021d8db4; size: 0x64.
extern "C" int Combat_AdjustInputByCombatantFlags(void* unused0, unsigned unused1, int index, unsigned unused3, unsigned unused4, int value) {
    void* combatant = _ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(), index);
    if (combatant == 0) return value;
    if (CombatStatus_HasSleep((unsigned*)*(void**)((char*)combatant + 0x138))) goto adjust;
    if (*(unsigned*)((char*)*(void**)((char*)combatant + 0x138) + 0x14) & 0x20) goto adjust;
    goto returnInput;
adjust:
    { unsigned converted = (unsigned)_fflt(value); _fmul(0x40000000, converted); return _ffix(); }
returnInput:
    return value;
}

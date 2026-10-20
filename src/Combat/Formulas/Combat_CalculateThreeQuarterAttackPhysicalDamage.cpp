#include <globaldefs.h>
ARM
struct Random;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" unsigned _Z23CalculatePhysicalDamageiiP6Random(int,int,Random*);
extern "C" unsigned _ffltu(unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ffix(unsigned);
// Original: arm9/ov024 @ 0x021D8AD8; symbol: func_ov024_021d8ad8; size: 0x90.
extern "C" int Combat_CalculateThreeQuarterAttackPhysicalDamage(Random** random,int attacker,int defender,int unused1,int unused2,int fallback) {
 void* state=_ZN9GameState11GetInstanceEv();
 char* a=_ZN9GameState19GetCombatantByIndexEi(state,attacker);
 char* b=_ZN9GameState19GetCombatantByIndexEi(state,defender);
 if(!a || !b) return fallback;
 Random* rng=*random;
 unsigned attack=*(unsigned short*)(*(char**)(a+0x138)+8);
 unsigned defense=*(unsigned short*)(*(char**)(b+0x138)+10);
 int scaled=_ffix(_fmul(0x3f400000,_ffltu(attack)));
 int def=_ffix(_ffltu(defense));
 return _ffix(_Z23CalculatePhysicalDamageiiP6Random(scaled,def,rng));
}

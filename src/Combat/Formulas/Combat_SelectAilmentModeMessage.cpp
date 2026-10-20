#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned Combat_SelectMessageForPartyOrMonster(...);
extern "C" unsigned CombatStatus_HasAilmentModeTwo(...);
extern "C" unsigned CombatStatus_HasAilmentModeOne(...);
extern "C" unsigned _Z16GetCombatantByIDii(...);
// Original: arm9/ov024 @ 0x021e939c; symbol: SelectCombatantModeMessageCode.
extern "C" int Combat_SelectAilmentModeMessage(char* p,int index,int first,int second){char* object=(char*)_Z16GetCombatantByIDii(U(p,0x10),index);if(!object)return 0;int mode2=CombatStatus_HasAilmentModeTwo((void*)U(object,0x138));int mode1=CombatStatus_HasAilmentModeOne((void*)U(object,0x138));if(first){if(second)return mode2?0x10c:0x10a;if(mode2)return 0x10b;return Combat_SelectMessageForPartyOrMonster(index,0x26d,27);}if(second)return mode1?0x53:0x3f;if(mode2)return 0x10b;if(mode1)return 0x52;return Combat_SelectMessageForPartyOrMonster(index,0x26d,27);}

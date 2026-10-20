#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned BattleMenu_GetAbilityChoice(...);
extern "C" unsigned GameObject_GetLinkedIndexedState(...);
extern "C" unsigned BattleMenu_GetSpellChoice(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState21GetPartyMemberByIndexEi(...);
// Original: arm9/ov000 @ 0x0217aa78; symbol: FindPartyResourceCodeIndexOrClear.
struct ResourceCode{unsigned code:12,unused:20;};
extern "C" int BattleMenu_FindRememberedActionSelection(char* p,int count,int alternate){if(!p)return 0;int partyIndex=(signed char)*(volatile unsigned*)(p+0x4c);void* member=(void*)_ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(),partyIndex);if(!member)return 0;char* state=(char*)GameObject_GetLinkedIndexedState(member);if(!state)return 0;unsigned short code=H(state,0x960);if(alternate)code=H(state,0x962);for(short i=0;i<count;i++){char* record=(char*)BattleMenu_GetSpellChoice(p,i);if(alternate)record=(char*)BattleMenu_GetAbilityChoice(p,i);if(record&&code==((ResourceCode*)(record+4))->code)return i;}if(alternate)H(state,0x962)=0;else H(state,0x960)=0;return 0;}

#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned char* GameState_GetIndexList(void*);extern "C" char* _ZN9GameState21GetPartyMemberByIndexEi(void*,int);extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);extern "C" int GameState_TestAllListedObjectLinkedFlags(unsigned char*);extern "C" bool GameObject_IsDead(void*);
// Original: arm9/ov000 @ 0x02163C80; symbol: GameState_TestReadyLinkedPartyAgainstCombatants; size: 0x114.
extern "C" int GameState_TestReadyLinkedPartyAgainstCombatants(char* self,int checkCombatants){
void* game=_ZN9GameState11GetInstanceEv();unsigned char* list=GameState_GetIndexList(game);int partyReady=1;for(int i=0;i<4;++i){char* object=_ZN9GameState21GetPartyMemberByIndexEi(game,i);if(object&&!PartySelection_GetMemberMask((unsigned char*)V(self,0x2a0),(unsigned char)i)){if(!(U(V(object,0x130),0)&1))partyReady=0;}}int linked=GameState_TestAllListedObjectLinkedFlags(list)!=0;if(checkCombatants){linked=1;for(int i=0;i<4;++i){char* object=_ZN9GameState19GetCombatantByIndexEi(game,i);if(object&&PartySelection_GetMemberMask((unsigned char*)V(self,0x2a0),(unsigned char)i)&&!GameObject_IsDead(object))linked=0;}}if(linked&&!partyReady){char* data=V(self,0x2a0);if(B(data,36)||B(data,37))return 1;}return 0;
}

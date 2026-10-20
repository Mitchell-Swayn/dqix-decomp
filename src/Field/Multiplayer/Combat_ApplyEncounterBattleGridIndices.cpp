#include <globaldefs.h>
ARM
extern "C" int FieldBattle_GetEncounterRequest(...);
extern "C" int FieldBattle_GetScene(...);
extern "C" int FieldBattle_GetCombatContext(...);
extern "C" int GameObject_SetBattleGridIndex(...);
extern "C" int _ZN9GameState19GetCombatantByIndexEi(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021C8AB0; symbol: ApplyPacketFlagMasksToPartyAndExtendedCombatants; size: 0xc8.
extern "C" void Combat_ApplyEncounterBattleGridIndices(int unused,char* packet,void* state,char* resources){
void* owner=P(resources,0x3718);char* descriptor=C(FieldBattle_GetEncounterRequest(owner));if(!descriptor)return;if(!FieldBattle_GetScene(owner))return;if(!FieldBattle_GetCombatContext(owner))return;char* masks=packet+4;if(H(descriptor,8)!=H(masks,12))return;for(int i=0;i<4;i++){void* object=(void*)_ZN9GameState19GetCombatantByIndexEi(state,i);if(object&&B(masks,i)!=255)GameObject_SetBattleGridIndex(object,B(masks,i));}for(int i=0;i<8;i++){void* object=(void*)_ZN9GameState19GetCombatantByIndexEi(state,i+192);if(object&&B(masks+4,i)!=255)GameObject_SetBattleGridIndex(object,B(masks+4,i));}
}

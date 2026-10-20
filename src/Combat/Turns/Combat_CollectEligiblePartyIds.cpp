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
#pragma always_inline on
extern "C" void* _ZN9GameState11GetInstanceEv();extern "C" unsigned GameState_CopyActivePartySlotList(void*,void*);extern "C" int Combat_ClassifySpecialEncounterSpecies(unsigned char*);extern "C" unsigned PartySelection_GetMemberMask(unsigned char*,unsigned);extern "C" char* GameState_GetObjectWithFlag100(void*,int);extern "C" int Combat_IsCombatantExcludedFromSelection(char*);extern "C" bool GameObject_IsDead(void*);struct Mode{unsigned char value:4;unsigned char other:4;};inline int HasMode(char* object){char* p=V(object,0x150);if(p)return ((Mode*)(p+0x56b))->value!=0;return 0;}
// Original: arm9/ov000 @ 0x0215E9FC; symbol: Combat_CollectEligiblePartyIds; size: 0x120.
extern "C" int Combat_CollectEligiblePartyIds(void* context,short* output,int limit,int flags){
void* game=_ZN9GameState11GetInstanceEv();unsigned char ids[4];int count=GameState_CopyActivePartySlotList(game,ids);int total=0;int mode;int living=flags&1;mode=flags&8;for(int i=0;i<count;++i){int id=ids[i];if(Combat_ClassifySpecialEncounterSpecies((unsigned char*)context)&&id)continue;if(!PartySelection_GetMemberMask((unsigned char*)V((char*)context,0x8e18),(unsigned char)id))continue;char* object=GameState_GetObjectWithFlag100(game,id);if(!object||Combat_IsCombatantExcludedFromSelection(object))continue;if(living&&GameObject_IsDead(object))continue;if(mode&&HasMode(object))continue;output[total++]=id;if(total==limit)return total;}return total;
}

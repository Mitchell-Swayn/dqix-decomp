#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" bool GameObject_IsDead(void*);
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int PartyRoster_ContainsActiveObjectIndex(unsigned char*,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_TestCombatantBlockingFlags(void*,int,int);
extern "C" void Combat_IncrementCappedEventCounter(unsigned char*,int);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" void Combat_AppendTaggedTargetToHistory(char*,unsigned short,unsigned char);
extern "C" float Combat_GetCurrentHealthFraction(unsigned char*);
extern "C" int Combatant_IsExcludedFromActionResolution(void*);
extern "C" void* memset(void*,int,unsigned);
struct Ids{short value[8];};struct Indices{int value[8];};
// Original data: arm9/ov024 @ 0x21fe6f8; symbol: data_ov024_021fe6f8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
// Original data: arm9/ov024 @ 0x21fe7e0; symbol: data_ov024_021fe7e0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffff00000000000000000000000000000000000000000000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" Ids CombatRetargetThroughCategoryPriorityLists_UnknownRoleInitializedBytes;extern "C" Indices CombatRetargetThroughCategoryPriorityLists_UnknownRoleInitializedBytes_Variant2;
struct Link{char pad[0x2a];short id;int Index(){return id;}};
struct Nested{char pad[0x21];unsigned char category;int IsEight(){return category==8;}int IsSeven(){return category==7;}int IsSix(){return category==6;}};
static inline int IsParty(int index){return index>=0&&index<=3;}
// Original: arm9/ov024 @ 0x021E9B74; symbol: func_ov024_021e9b74; size: 0x3F4.
// Retargets through category8, low-ratio category7, then linked category6 candidates and emits the selected tag.
extern "C" int Combat_RetargetThroughCategoryPriorityLists(char* self,int unused,short* target,char* descriptor){
 if(!*(char**)(self+12))return 0;
 char* original=_Z16GetCombatantByIDii(*(int*)(self+16),*target);if(!original)return 0;
 if(GameObject_IsDead(original)||Combatant_IsExcludedFromActionResolution(original))return 0;
 _ZN9GameState11GetInstanceEv();
 char* record;int found;int random;random=*(int*)(self+16);record=*(char**)(self+12);
 if(*(unsigned*)(descriptor+16)&0x1000){
 Ids ids=CombatRetargetThroughCategoryPriorityLists_UnknownRoleInitializedBytes;int count;
 int party=0;int id=*target;if(id>=0&&id<=3)party=1;
 if(party)count=Combat_CollectEligiblePartyIds(*(void**)(self+16),ids.value,8,1);else count=Combat_CollectGroupIndicesByDescriptorFlags(*(char**)(self+16),ids.value,8,1);
 Indices candidates=CombatRetargetThroughCategoryPriorityLists_UnknownRoleInitializedBytes_Variant2;found=0;
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*(int*)(self+16),ids.value[i]);if(object&&*target!=ids.value[i]&&!Combat_TestCombatantBlockingFlags(*(void**)(self+16),ids.value[i],0)&&((Nested*)*(char**)(object+0x138))->IsEight())candidates.value[found++]=ids.value[i];}
 if(found>0){*target=candidates.value[_Z13NextRandomMaxP6Randomi((void*)random,found)];((void(*)(char*,int,int))Combat_AppendTaggedTargetToHistory)(record,*target,6);*(unsigned char*)(self+0x79)=1;return 1;}
 found=0;memset(candidates.value,-1,32);
 if(Combat_GetCurrentHealthFraction((unsigned char*)original)<=0.08f){
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*(int*)(self+16),ids.value[i]);if(object&&*target!=ids.value[i]&&!Combat_TestCombatantBlockingFlags(*(void**)(self+16),ids.value[i],0)&&((Nested*)*(char**)(object+0x138))->IsSeven())candidates.value[found++]=ids.value[i];}
 if(found>0){*target=candidates.value[_Z13NextRandomMaxP6Randomi((void*)random,found)];((void(*)(char*,int,int))Combat_AppendTaggedTargetToHistory)(record,*target,7);*(unsigned char*)(self+0x79)=1;return 1;}
 }
 found=0;memset(candidates.value,-1,32);
 for(int i=0;i<count;i++){char* object=_Z16GetCombatantByIDii(*(int*)(self+16),ids.value[i]);if(object&&!Combat_TestCombatantBlockingFlags(*(void**)(self+16),ids.value[i],0)&&((Nested*)*(char**)(object+0x138))->IsSix()&&*target==((Link*)*(char**)(object+0x138))->Index())candidates.value[found++]=ids.value[i];}
 if(found>0){*target=candidates.value[_Z13NextRandomMaxP6Randomi((void*)random,found)];((void(*)(char*,int,int))Combat_AppendTaggedTargetToHistory)(record,*target,8);*(unsigned char*)(self+0x79)=1;if(PartyRoster_ContainsActiveObjectIndex((unsigned char*)GameState_GetIndexList((GameState*)_ZN9GameState11GetInstanceEv()),*target))Combat_IncrementCappedEventCounter(*(unsigned char**)(self+16),4);return 1;}
 memset(candidates.value,-1,32);
 }
 return 0;
}

#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" bool GameObject_IsDead(void*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" int Combat_HasForcedTarget(void*);
extern "C" int Combat_HasReducedTargetWeightStatus(void*);
struct Flag30 { unsigned rest:30,value:1,top:1; };
struct Flag26 { unsigned rest:26,value:1,top:5; };
struct Weights { int value[4]; };
struct Indices { short value[8]; };
// Original data: arm9/ov000 @ 0x2182ca4; symbol: data_ov000_02182ca4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 01000000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" Weights SelectWeightedEligibleCombatantIndex_UnknownRoleInitializedBytes;
extern "C" Indices SelectWeightedEligibleCombatantIndex_CombatantSelectionInitialIds;
// Original: arm9/ov000 @ 0x02154F30; symbol: func_ov000_02154f30; size: 0x224.
extern "C" int SelectWeightedEligibleCombatantIndex(void* random,unsigned sourceIndex,int count,short* input) {
 int i;
 unsigned char n;
 char* source=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),sourceIndex);
 char* config=*(char**)(source+0x148);
 Weights weights=SelectWeightedEligibleCombatantIndex_UnknownRoleInitializedBytes;
 int sum=0;
 if(Combat_HasForcedTarget(source)) {
 int index=*(short*)(*(char**)(source+0x138)+0x2e);
 void* state=_ZN9GameState11GetInstanceEv();
 char* forced=_ZN9GameState19GetCombatantByIndexEi(state,index);
 if(forced && !GameObject_IsDead(forced) && !Combat_IsCombatantExcludedFromSelection(forced)) return *(short*)(*(char**)(source+0x138)+0x2e);
 }
 Indices candidates=SelectWeightedEligibleCombatantIndex_CombatantSelectionInitialIds;
 n=0;
 for(i=0;i<count;i++) {
 int index=input[i];
 void* state=_ZN9GameState11GetInstanceEv();
 char* obj=_ZN9GameState19GetCombatantByIndexEi(state,index);
 if(!obj || GameObject_IsDead(obj) || Combat_IsCombatantExcludedFromSelection(obj)) continue;
 unsigned short flag=((Flag30*)(*(char**)(obj+0x134)+0x3c))->value;
 weights.value[n]=flag==0?2:1;
 if(((Flag26*)(config+0x10))->value==1) {
 char* nested=*(char**)(source+0x138);
 int candidate=input[i];
 if(candidate==*(short*)(nested+0x32)) weights.value[n]+=2;
 if(candidate==*(short*)(nested+0x34)) weights.value[n]++;
 }
 index=*(volatile int*)&weights.value[n];
 candidates.value[n]=input[i];
 sum+=index;
 if(Combat_HasReducedTargetWeightStatus(obj)) weights.value[n]>>=1;
 n++;
 }
 if(n==0) return -1;
 int roll=_Z13NextRandomMaxP6Randomi(random,sum)+1;
 for(int i=0;i<n;i++) {
 if(weights.value[i]>=roll) return candidates.value[i];
 roll-=weights.value[i];
 }
 return candidates.value[_Z13NextRandomMaxP6Randomi(random,n)];
}

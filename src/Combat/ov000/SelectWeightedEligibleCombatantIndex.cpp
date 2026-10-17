#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,unsigned);
extern "C" bool Object_TestNestedOffset138Word14Bit0(void*);
extern "C" int _Z13NextRandomMaxP6Randomi(void*,int);
extern "C" int TestNestedRecordFlag2000(char*);
extern "C" int HasNestedField138Flag1000At18(void*);
extern "C" int HasNestedField138Flag08000000At14(void*);
struct Flag30 { unsigned rest:30,value:1,top:1; };
struct Flag26 { unsigned rest:26,value:1,top:5; };
struct Weights { int value[4]; };
struct Indices { short value[8]; };
extern "C" Weights data_ov000_02182ca4;
extern "C" Indices data_ov000_02182c94;
// Original: arm9/ov000 @ 0x02154F30; symbol: func_ov000_02154f30; size: 0x224.
extern "C" int SelectWeightedEligibleCombatantIndex(void* random,unsigned sourceIndex,int count,short* input) {
 int i;
 unsigned char n;
 char* source=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),sourceIndex);
 char* config=*(char**)(source+0x148);
 Weights weights=data_ov000_02182ca4;
 int sum=0;
 if(HasNestedField138Flag1000At18(source)) {
 int index=*(short*)(*(char**)(source+0x138)+0x2e);
 void* state=_ZN9GameState11GetInstanceEv();
 char* forced=_ZN9GameState19GetCombatantByIndexEi(state,index);
 if(forced && !Object_TestNestedOffset138Word14Bit0(forced) && !TestNestedRecordFlag2000(forced)) return *(short*)(*(char**)(source+0x138)+0x2e);
 }
 Indices candidates=data_ov000_02182c94;
 n=0;
 for(i=0;i<count;i++) {
 int index=input[i];
 void* state=_ZN9GameState11GetInstanceEv();
 char* obj=_ZN9GameState19GetCombatantByIndexEi(state,index);
 if(!obj || Object_TestNestedOffset138Word14Bit0(obj) || TestNestedRecordFlag2000(obj)) continue;
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
 if(HasNestedField138Flag08000000At14(obj)) weights.value[n]>>=1;
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

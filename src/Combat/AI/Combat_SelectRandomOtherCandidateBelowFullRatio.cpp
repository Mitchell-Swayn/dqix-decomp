#include <globaldefs.h>
ARM
struct GameObject;
extern "C" GameObject* Combat_FindIndexedMonsterObject(void*,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
struct NestedRecord {unsigned short pad,current,pad4,maximum;unsigned Maximum(){return maximum;}};
// Original data: arm9/ov024 @ 0x21feeac; symbol: data_ov024_021feeac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IdList{short ids[8];};extern "C" IdList CombatSelectRandomOtherCandidateBelowFullRatio_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F3C3C; symbol: func_ov024_021f3c3c; size: 0x13C.
// Requires the current object's nested count, excludes supplied ID, and selects a candidate whose nested halfword ratio is below one.
extern "C" int Combat_SelectRandomOtherCandidateBelowFullRatio(int* self,int excluded,int unused,int* result,short* output){
 char* current=(char*)((GameObject*(*)(void*))Combat_FindIndexedMonsterObject)((void*)*self);
 if(!current)return 0;if(!*(unsigned short*)(*(char**)(current+0x138)+2))return 0;
 IdList list=CombatSelectRandomOtherCandidateBelowFullRatio_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags((char*)*self,list.ids,8,1);
 if(count<=0)return 0;*result=0;
 for(int i=0;i<count;i++){
 if(excluded==list.ids[i])continue;
 char* object=_Z16GetCombatantByIDii(*self,list.ids[i]);
 if(object){char* nested=*(char**)(object+0x138);unsigned denominator=((NestedRecord*)nested)->Maximum();if((float)(unsigned)*(unsigned short*)(nested+2)/(float)denominator>=1.0f)continue;output[(*result)++]=list.ids[i];}
 }
 if(*result<=0)return 0;Combat_SelectRandomCandidateInPlace((void**)self,result,output);return 1;
}

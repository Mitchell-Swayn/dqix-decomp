#include <globaldefs.h>
ARM
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" char* _Z16GetCombatantByIDii(int,int);
struct A; struct Record;
extern "C" int CombatStatus_HasAilmentModeTwo(A*);
extern "C" int CombatStatus_HasAilmentModeOne(Record*);
extern "C" bool Combat_TestFlaggedCandidatesBelowOneThird(int*);
extern "C" void* memcpy(void*,const void*,unsigned);
struct NestedRecord{char padding[0x4d];unsigned char value;int ReadValue(){return value;}};
struct IdList{short ids[4];};
// Original data: arm9/ov024 @ 0x21feb4c; symbol: data_ov024_021feb4c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" IdList CombatCopyCandidatesWhenTwoThirdsHavePositiveByte4D_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F4B60; symbol: func_ov024_021f4b60; size: 0x12C.
// Copies all candidate IDs when two thirds have a positive nested byte 4d and clear mode flags, subject to the linked-flag minority gate.
extern "C" int Combat_CopyCandidatesWhenTwoThirdsHavePositiveByte4D(int* self,int unused1,int unused2,int* result,short* output){
 IdList list=CombatCopyCandidatesWhenTwoThirdsHavePositiveByte4D_UnknownRoleInitializedBytes;
 int count=Combat_CollectEligiblePartyIds((void*)*self,list.ids,4,1);
 if(count<=0)return 0;
 if(!Combat_TestFlaggedCandidatesBelowOneThird(self))return 0;
 *result=0;
 for(int i=0;i<count;i++){
  char* object=_Z16GetCombatantByIDii(*self,list.ids[i]);
  if(object&&!CombatStatus_HasAilmentModeOne(*(Record**)(object+0x138))&&!CombatStatus_HasAilmentModeTwo(*(A**)(object+0x138))&&(((NestedRecord*)*(char**)(object+0x138))->ReadValue()>0))output[(*result)++]=list.ids[i];
 }
 if(*result<=0)return 0;
 if(*result*3<count*2)return 0;
 *result=count;memcpy(output,list.ids,8);return 1;
}

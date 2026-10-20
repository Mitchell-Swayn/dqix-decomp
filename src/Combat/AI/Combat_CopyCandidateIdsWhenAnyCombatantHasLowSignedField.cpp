#include <globaldefs.h>
ARM
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(int,short*,int,int);
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);
extern "C" int Combat_SelectRandomCandidateInPlace(void*,int*,short*);
extern "C" char* Combat_FindIndexedMonsterObject(int);
extern "C" int Combatant_TestTargetCapabilityBit2(void*);
extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov024 @ 0x21fef5c; symbol: data_ov024_021fef5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatCopyCandidateIdsWhenAnyCombatantHasLowSignedField_UnknownRoleInitializedBytes[];
struct IdList {short ids[8];};

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021F1578; symbol: Combat_CopyCandidateIdsWhenAnyCombatantHasLowSignedField; size: 0xF4.
extern "C" int Combat_CopyCandidateIdsWhenAnyCombatantHasLowSignedField(char* self,int unused1,int unused2,int* result,short* output){
 char* object=Combat_FindIndexedMonsterObject(W(self,0));if(!object)return 0;if(!Combatant_TestTargetCapabilityBit2(object))return 0;
 IdList list=*(IdList*)CombatCopyCandidateIdsWhenAnyCombatantHasLowSignedField_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(W(self,0),list.ids,8,1);if(count<=0)return 0;
 int found=0;for(int i=0;i<count;++i){object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&((W(P(object,0x138),0x58)<<8)>>29)<2){found=1;break;}}
 if(!found)return 0;*result=count;memcpy(output,list.ids,16);return 1;
}
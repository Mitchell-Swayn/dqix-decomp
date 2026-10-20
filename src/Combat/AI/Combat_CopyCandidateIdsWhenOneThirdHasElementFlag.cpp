#include <globaldefs.h>
ARM
struct IdList {short ids[8];};
// Original data: arm9/ov024 @ 0x21feecc; symbol: data_ov024_021feecc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatCopyCandidateIdsWhenOneThirdHasElementFlag_UnknownRoleInitializedBytes[];
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" bool CombatStatus_HasSleep(unsigned*);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021EEAB8; symbol: Combat_CopyCandidateIdsWhenOneThirdHasElementFlag; size: 0x104.
extern "C" int Combat_CopyCandidateIdsWhenOneThirdHasElementFlag(char* self,int unused1,int unused2,int* result,short* output){IdList list=*(IdList*)CombatCopyCandidateIdsWhenOneThirdHasElementFlag_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(P(self,0),list.ids,8,1);if(count<=0)return 0;*result=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&(!Combatant_TestPrimaryStatusFlagBit9(object)&&(CombatStatus_HasSleep((unsigned*)P(object,0x138)))))output[(*result)++]=list.ids[i];}if(*result<=0)return 0;if(*result*3<count*1)return 0;*result=count;memcpy(output,list.ids,16);return 1;}
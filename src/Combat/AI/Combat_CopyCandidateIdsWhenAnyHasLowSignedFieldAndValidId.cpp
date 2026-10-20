#include <globaldefs.h>
ARM
struct IdList {short ids[8];};
// Original data: arm9/ov024 @ 0x21fedac; symbol: data_ov024_021fedac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatCopyCandidateIdsWhenAnyHasLowSignedFieldAndValidId_UnknownRoleInitializedBytes[];
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(char*,short*,int,unsigned);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" bool CombatStatus_HasSleep(unsigned*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov024 @ 0x021F6298; symbol: Combat_CopyCandidateIdsWhenAnyHasLowSignedFieldAndValidId; size: 0x104.
extern "C" int Combat_CopyCandidateIdsWhenAnyHasLowSignedFieldAndValidId(char* self,int unused1,int unused2,int* result,short* output){IdList list=*(IdList*)CombatCopyCandidateIdsWhenAnyHasLowSignedFieldAndValidId_UnknownRoleInitializedBytes;int count=Combat_CollectGroupIndicesByDescriptorFlags(P(self,0),list.ids,8,1);if(count<=0)return 0;*result=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&(H(P(object,0x138),8)<65535&&((W(P(object,0x138),0x58)<<29)>>29)<2))output[(*result)++]=list.ids[i];}if(*result<=0)return 0;*result=count;memcpy(output,list.ids,16);return 1;}
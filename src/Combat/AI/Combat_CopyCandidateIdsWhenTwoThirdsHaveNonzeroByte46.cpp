#include <globaldefs.h>
ARM
struct IdList {short ids[4];};
// Original data: arm9/ov024 @ 0x21fea5c; symbol: data_ov024_021fea5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" short CombatCopyCandidateIdsWhenTwoThirdsHaveNonzeroByte46_UnknownRoleInitializedBytes[];
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combat_CollectEligiblePartyIds(int,short*,int,int);
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" bool CombatStatus_HasSleep(unsigned*);
extern "C" int CombatEffect_TargetHasDazzle(void*);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct ElementRecord {char pad[70];unsigned char value;int ReadValue(){return value;}};
// Original: arm9/ov024 @ 0x021F4ED4; symbol: Combat_CopyCandidateIdsWhenTwoThirdsHaveNonzeroByte46; size: 0x104.
extern "C" int Combat_CopyCandidateIdsWhenTwoThirdsHaveNonzeroByte46(char* self,int unused1,int unused2,int* result,short* output){IdList list=*(IdList*)CombatCopyCandidateIdsWhenTwoThirdsHaveNonzeroByte46_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds(W(self,0),list.ids,4,1);if(count<=0)return 0;*result=0;for(int i=0;i<count;++i){char* object=_Z16GetCombatantByIDii(W(self,0),list.ids[i]);if(object&&(!CombatEffect_TargetHasDazzle(object)&&(((ElementRecord*)P(object,0x138))->ReadValue()>0)))output[(*result)++]=list.ids[i];}if(*result<=0)return 0;if(*result*3<count*2)return 0;*result=count;memcpy(output,list.ids,8);return 1;}
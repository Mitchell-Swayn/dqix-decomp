#include <globaldefs.h>
ARM
extern "C" int Combat_SelectRandomCandidateInPlace(void**,int*,short*);
extern "C" int Combatant_HasFatalDamageProtection(void*);
extern "C" char* _Z16GetCombatantByIDii(void*,int);
extern "C" int Combat_CollectGroupIndicesByDescriptorFlags(void*,short*,int,int);
// Original data: arm9/ov024 @ 0x21fed3c; symbol: data_ov024_021fed3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Eight {short values[8];}; extern "C" Eight SelectRandomLivingCandidateWithoutDescriptorFlag_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F2D98; symbol: SelectRandomLivingCandidateWithoutDescriptorFlag; size: 0xf0.
// Collects living candidates without descriptor flag 0x400000 and selects one at random.
extern "C" int SelectRandomLivingCandidateWithoutDescriptorFlag(void** self,int unused1,int unused2,int* count,short* output){
 Eight ids=SelectRandomLivingCandidateWithoutDescriptorFlag_UnknownRoleInitializedBytes;
 int total=Combat_CollectGroupIndicesByDescriptorFlags(*self,ids.values,8,1);
 if(total<=0)return 0;
 *count=0;
 for(int i=0;i<total;i++){
  void* object=_Z16GetCombatantByIDii(*self,ids.values[i]);
  if(!object)continue;
  if(Combatant_HasFatalDamageProtection(object))continue;
  int life=(int)*(unsigned char*)((char*)*(void**)((char*)object+0x138)+0x48);
  if(life<=0)continue;
  output[(*count)++]=ids.values[i];
 }
 if(*count<=0)return 0;
 Combat_SelectRandomCandidateInPlace(self,count,output);
 return 1;
}

#include <globaldefs.h>
ARM
struct LinkedDescriptorView;struct ContextFlagOwner14;struct ContextFlagOwner30;struct ContextFlagOwner31;
extern "C" char* _Z16GetCombatantByIDii(int,int);
extern "C" int Combatant_TestPrimaryStatusFlagBit9(void*);
extern "C" int Combatant_TestPrimaryStatusFlagBit27(ContextFlagOwner14*);
extern "C" int Combatant_TestPrimaryStatusFlagBit30(ContextFlagOwner30*);
extern "C" int Combatant_TestPrimaryStatusFlagBit31(ContextFlagOwner31*);
extern "C" int Combatant_HasFatalDamageProtection(unsigned char*);
extern "C" int Combatant_TestPrimaryStatusFlagBit28(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit29(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit26(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit20(LinkedDescriptorView*);
extern "C" int Combatant_TestPrimaryStatusFlagBit21(LinkedDescriptorView*);
extern "C" int Combat_HasOrdinaryTension(LinkedDescriptorView*);
extern "C" int Combat_HasSuperHighTension(void*);
extern "C" bool CombatStatus_HasAttributeWard(unsigned*);
extern "C" int Combatant_TestSecondaryStatusFlagBit3(const void*);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" void* memcpy(void*,const void*,unsigned);
// Original data: arm9/ov024 @ 0x21fea3c; symbol: data_ov024_021fea3c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct IdList{short ids[4];};extern "C" IdList CombatCopyPartyCandidatesWhenAnyHasListedStatus_UnknownRoleInitializedBytes;
struct Status {signed a:3,b:3,c:3,d:3,e:3,f:3,g:3,h:3,i:3,j:3,rest:2;};
// Original: arm9/ov024 @ 0x021F3E64; symbol: func_ov024_021f3e64; size: 0x264.
// Copies all party candidates when any has a listed descriptor flag or nonbaseline signed status.
extern "C" int Combat_CopyPartyCandidatesWhenAnyHasListedStatus(int* self,int unused1,int unused2,int* result,short* output){
 IdList list=CombatCopyPartyCandidatesWhenAnyHasListedStatus_UnknownRoleInitializedBytes;int count=Combat_CollectEligiblePartyIds((void*)*self,list.ids,4,1);if(count<=0)return 0;
 int found=0;*result=0;
 for(int i=0;i<count;i++){
 char* object=_Z16GetCombatantByIDii(*self,list.ids[i]);if(!object)continue;
 if(Combat_HasOrdinaryTension((LinkedDescriptorView*)object)||Combat_HasSuperHighTension(object)||Combatant_TestPrimaryStatusFlagBit9(object)||Combatant_TestPrimaryStatusFlagBit27((ContextFlagOwner14*)object)||Combatant_TestPrimaryStatusFlagBit28((LinkedDescriptorView*)object)||Combatant_TestPrimaryStatusFlagBit29((LinkedDescriptorView*)object)||Combatant_TestPrimaryStatusFlagBit20((LinkedDescriptorView*)object)||Combatant_HasFatalDamageProtection((unsigned char*)object)||Combatant_TestPrimaryStatusFlagBit26((LinkedDescriptorView*)object)||Combatant_TestPrimaryStatusFlagBit30((ContextFlagOwner30*)object)||Combatant_TestPrimaryStatusFlagBit26((LinkedDescriptorView*)object)||Combatant_TestPrimaryStatusFlagBit21((LinkedDescriptorView*)object)||Combatant_TestPrimaryStatusFlagBit31((ContextFlagOwner31*)object)||CombatStatus_HasAttributeWard(*(unsigned**)(object+0x138))||Combatant_TestSecondaryStatusFlagBit3(object))goto qualifying;
 {char* nested=*(char**)(object+0x138);unsigned flags=*(unsigned*)(nested+24);
 if(flags&2)goto qualifying;if(flags&4)goto qualifying;if(flags&0x200)goto qualifying;if(flags&0x400)goto qualifying;if(flags&0x100)goto qualifying;
 Status* status=(Status*)(nested+0x58);
 if(status->a>0||status->b>0||status->c>0||status->d!=0||status->e>0||status->f!=0||status->g>0||status->h!=0||status->i!=0||status->j!=0)goto qualifying;
 }continue;
 qualifying: found=1;
 }
 if(!found)return 0;*result=count;memcpy(output,list.ids,8);return 1;
}

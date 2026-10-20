#include <globaldefs.h>
#include "std_library_functions.h"
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
extern "C" bool Combat_TestPartyFlagsAndUnrestrictedDescriptor(int*,int);
// Original data: arm9/ov024 @ 0x21fef0c; symbol: data_ov024_021fef0c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff0000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char CombatCopyPartyIdsWhenAnyDescriptorIsEligible_UnknownRoleInitializedBytes[];
struct EightHalfwords {short ids[8];};
// Original: arm9/ov024 @ 0x021F10E0; symbol: func_ov024_021f10e0; size: 0xB8.
// Copies all collected ids only if at least one passes the descriptor predicate.
extern "C" ARM int Combat_CopyPartyIdsWhenAnyDescriptorIsEligible(int* self,void* unused,void* unused2,int* outputCount,short* output){
 EightHalfwords values=*(EightHalfwords*)CombatCopyPartyIdsWhenAnyDescriptorIsEligible_UnknownRoleInitializedBytes;
 int count=Combat_CollectEligiblePartyIds((void*)*self,values.ids,4,1);
 if(count<=0)return 0;
 int found=0;
 for(int i=0;i<count;i++){if(Combat_TestPartyFlagsAndUnrestrictedDescriptor(self,values.ids[i])){found=1;break;}}
 if(!found)return 0;
 *outputCount=count;memcpy(output,values.ids,16);return 1;
}

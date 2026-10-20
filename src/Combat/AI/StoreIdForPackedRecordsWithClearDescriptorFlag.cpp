#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void*,int,int,int);
extern "C" int Combat_FindIndexedMonsterObject(void*,int);
extern "C" int Combatant_TestPrimaryStatusFlagBit29(void*);
extern "C" int Combat_CollectEligiblePartyIds(void*,short*,int,int);
// Original data: arm9/ov024 @ 0x21feb9c; symbol: data_ov024_021feb9c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffff000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
struct Four {short values[4];}; extern "C" Four StoreIdForPackedRecordsWithClearDescriptorFlag_UnknownRoleInitializedBytes;
// Original: arm9/ov024 @ 0x021F2E88; symbol: StoreIdForPackedRecordsWithClearDescriptorFlag; size: 0xf0.
// Counts matching packed-mode records, then stores the requested ID when its linked descriptor flag is clear.
extern "C" int StoreIdForPackedRecordsWithClearDescriptorFlag(void** self,int requestedId,int unused,int* count,short* output){
 Four ids=StoreIdForPackedRecordsWithClearDescriptorFlag_UnknownRoleInitializedBytes;
 int total=Combat_CollectEligiblePartyIds(*self,ids.values,4,1);
 if(total<=0)return 0;
 *count=0;
 for(int i=0;i<total;i++)if(Combat_TestMonsterDescriptorMode(*self,ids.values[i],8,0))++*count;
 if(*count<=0)return 0;
 void* object=(void*)Combat_FindIndexedMonsterObject(*self,requestedId);
 if(!object)return 0;
 if(Combatant_TestPrimaryStatusFlagBit29(object))return 0;
 *output=(short)requestedId;
 *count=1;
 return 1;
}

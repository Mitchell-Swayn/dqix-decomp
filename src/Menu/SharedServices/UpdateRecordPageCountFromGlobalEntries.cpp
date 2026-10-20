#include <globaldefs.h>
ARM
struct State;
// Original data: arm9/ov004 @ 0x2171010; symbol: data_ov004_02171010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {extern unsigned char* PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage;void* Menu_GetDisplayRecordRegistry(State*);void* MenuRecordList_LocateByKey(void**,unsigned short);unsigned MenuRecord_GetType(void*);}
// Original: arm9/ov004 @ 0x02163530; symbol: func_ov004_02163530; size: 0xA0.
extern "C" void UpdateRecordPageCountFromGlobalEntries(State* owner){
*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f8)=1;
while((*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f8)<<3) < PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage[0x18f4])++*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f8);
char* record=(char*)MenuRecordList_LocateByKey((void**)Menu_GetDisplayRecordRegistry(owner),10);
if(!record)return;
if(MenuRecord_GetType(record)!=7)return;
*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f6)=*(short*)(record+0x5c);
short pages=*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f8);
short current=*(short*)(PopulateSelectedRecordTextPanel_UnknownRoleZeroInitializedStorage+0x18f6);
*(short*)(record+0x5c)=current;*(short*)(record+0x5e)=pages;
}

#include <globaldefs.h>
ARM
extern "C" {
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
void* Object_GetGlobalSixteenEntryDisplayState();
unsigned char* ObjectPool_GetDisplayEntryByObjectIndex(unsigned char*,int);
int Combat_DispatchSelectionProcedure(void*,void*,int,int*);
void* Combat_GetDisplayRecordSlot(void*,int);
}
// Original: arm9/ov025 @ 0x021E5014; symbol: func_ov025_021e5014; size: 0x88.
extern "C" int Combat_SetDisplayRecordSelectedTarget(unsigned char* action,void* selection,int unused,void* context) {
 int* entry=(int*)Combat_GetDisplayRecordSlot(*(void**)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage+12),action[9]);
 if(!entry) return 1;
 int index=*entry;
 unsigned char* display=(unsigned char*)Object_GetGlobalSixteenEntryDisplayState();
 unsigned char* record=ObjectPool_GetDisplayEntryByObjectIndex(display,index);
 if(!record) return 1;
 int ids[8];
 int count=Combat_DispatchSelectionProcedure(context,selection,action[8],ids);
 if(count!=1) { *(short*)(record+0xb2)=-1; return 1; }
 else { *(short*)(record+0xb2)=ids[0]; return 1; }
 return 1;
}

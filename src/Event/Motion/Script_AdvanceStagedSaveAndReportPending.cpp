#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(unsigned*,unsigned);
extern "C" void SystemState_ClearFlags(unsigned*,unsigned);
extern "C" int SaveData_AdvanceStagedSaveWrite(void*,void*,int,int);
extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
// Original: arm9/ov001 @ 0x02163070; symbol: SetStateMaskAndWriteInvertedOperationResult; size: 0x84.
extern "C" int Script_AdvanceStagedSaveAndReportPending(void *output) {
 if(!*(int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage+0x4b4))return 0;
 unsigned *flags=(unsigned*)SystemState_GetGlobalFlags();SystemState_SetFlags(flags,128);
 bool success=SaveData_AdvanceStagedSaveWrite((void*)*(int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage+0x4b4),(void*)*(int*)(EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage+0x4b8),10,0)!=0;
 Script_WriteIntegerReferenceOutput(output,!success);
 if(success)SystemState_ClearFlags(flags,128);return 1;
}

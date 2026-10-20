#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250bf8; symbol: data_ov031_02250bf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22489a4; symbol: data_ov031_022489a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 181716155f5e5d5c.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned char WfcUtilityCreateWirelessRegionIndicator_UnknownRoleInitializedBytes[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void* Resource_ExpandPackedTableToAllocatedBuffer(unsigned,unsigned);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void(*)(),unsigned,unsigned);
extern "C" void System_ExpandSharedEntriesAndSetHeaderFlags();
// Original: arm9/ov031 @ 0x02223A64; symbol: func_ov031_02223a64; size: 0xB8.
extern "C" void WfcUtility_CreateWirelessRegionIndicator(int index) {
if(WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage) return;
char* node=(char*)Memory_AllocateZeroedBlock(12,4);
unsigned code=WfcUtilityCreateWirelessRegionIndicator_UnknownRoleInitializedBytes[index*4];
WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage=node;
node[8]=index;
*(void**)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage=Resource_ExpandPackedTableToAllocatedBuffer(0,code);
**(unsigned**)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage=(**(unsigned**)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage&0xfe00ff00)|0xe50026;
*(unsigned short*)(*(char**)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage+4)=(*(unsigned short*)(*(char**)WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage+4)&~0xc00)|0x800;
*(void**)(WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage+4)=WfcUtility_CreateTaskWithBorrowedContext(0,System_ExpandSharedEntriesAndSetHeaderFlags,0,120);
}

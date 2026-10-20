#include <globaldefs.h>
ARM
struct State {char buffers[0x800];void* handles[2];void* task;};
// Original data: arm9/ov031 @ 0x2290d60; symbol: data_ov031_02290d60.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern State* WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage;void* Memory_AllocateZeroedBlock(unsigned,unsigned);void MIi_CpuClearFast(int,void*,unsigned);void* WfcUtility_CreateSteppedPointerRing(int,void*,int);void* WfcUtility_CreateTaskWithBorrowedContext(int,void(*)(),int,int);void Graphics_FlushAndLoadOAM();}
// Original: arm9/ov031 @ 0x0223D928; symbol: func_ov031_0223d928; size: 0x9C.
extern "C" void Resource_InitializeTwoBuffersAndCallbackTask(){
WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage=(State*)Memory_AllocateZeroedBlock(0x80c,4);
MIi_CpuClearFast(0x200,WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage,0x800);
int i=0;int offset=0;
do{void* handle=WfcUtility_CreateSteppedPointerRing(64,WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage->buffers+offset,8);offset+=0x400;WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage->handles[i]=handle;i++;}while(i<2);
void* task=WfcUtility_CreateTaskWithBorrowedContext(1,Graphics_FlushAndLoadOAM,0,200);WfcUtilityDestroyOamServices_UnknownRoleZeroInitializedStorage->task=task;
}

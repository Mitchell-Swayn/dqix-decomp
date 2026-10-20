#include <globaldefs.h>
ARM
extern "C" unsigned char* WfcUtility_GetEditableConnectionProfile();
// Original data: arm9/ov031 @ 0x22491d8; symbol: data_ov031_022491d8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 283e23023c3e230203010000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char ResourceCreateSharedSelectionAndInstallTimedCallback_UnknownRoleProcedureReferenceRecords[];
struct SelectionGlobal {unsigned a;void* selection;};
// Original data: arm9/ov031 @ 0x2290cd0; symbol: data_ov031_02290cd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" SelectionGlobal InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage;
extern "C" void MIi_CpuCopy32(const void*,void*,unsigned);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" void* Network_AllocateAndInitializeSharedWirelessWorkspaces(void*);
extern "C" void Memory_CopyIndexedStateBlock(unsigned,void*);
extern "C" void WfcUtility_FinishConnectionAttemptAndScheduleResultTransition();
extern "C" void WfcUtility_CreateTaskWithBorrowedContext(unsigned,void(*)(),unsigned,unsigned);
// Original: arm9/ov031 @ 0x02233B34; symbol: Resource_CreateSharedSelectionAndInstallTimedCallback; size: 0xa0.
// Builds selection configuration, stores created selection, initializes mode0 and installs120-tick callback.
extern "C" void Resource_CreateSharedSelectionAndInstallTimedCallback() {
 unsigned char* shared=WfcUtility_GetEditableConnectionProfile();char config[12];unsigned mode;
 MIi_CpuCopy32(ResourceCreateSharedSelectionAndInstallTimedCallback_UnknownRoleProcedureReferenceRecords,config,12);WfcUtility_GetScreenOperationArguments(0,&mode);
 if(mode==2)config[10]=4;else config[10]=shared[0xf4]+1;
 InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.selection=Network_AllocateAndInitializeSharedWirelessWorkspaces(config);
 if(InitializeBG2SharedSelectionAndCallback_UnknownRoleZeroInitializedStorage.selection && mode==0)Memory_CopyIndexedStateBlock(shared[0xf4],shared);
 WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_FinishConnectionAttemptAndScheduleResultTransition,0,120);
}

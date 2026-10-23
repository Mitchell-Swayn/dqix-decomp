#include "globaldefs.h"
// Original: arm9/ov031 @ 0x022276f8; symbol: AllocateAndInitializeSharedNetworkResourceContext.
// Original data: arm9/ov031 @ 0x224b66c; symbol: data_ov031_0224b66c.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 28b62402000000000000000054b624023cb624025901000000000000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c44; symbol: data_ov031_02290c44.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x2290c4c; symbol: data_ov031_02290c4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
struct Config{unsigned words[6];unsigned char status;unsigned char pad[3];};extern Config WfcUtilityCreateConnectionContext_UnknownRoleDataReferences;extern unsigned char *WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage;extern void *WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage;
extern "C" void* Memory_AllocateZeroedBlock(unsigned,int);extern "C" unsigned WfcUtility_GetMessageText(void*,int),Ov031_GetStatusCode();extern "C" void Wireless_InitializeDownloadSessionContext(void*,Config*);extern "C" int Network_ResetCommandForAcceptedStates();extern "C" void DisableInterruptsAndHaltForever(),WfcUtility_UpdateConnectionAndDispatchEvents(void*,void*);extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" ARM void WfcUtility_CreateConnectionContext(unsigned argument){WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage=(unsigned char*)Memory_AllocateZeroedBlock(0x1e2a4,32);*(unsigned*)(WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage+0x1e298)=argument;WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage[0x1e2a0]=0;WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage[0x1e2a1]=0;Config config=WfcUtilityCreateConnectionContext_UnknownRoleDataReferences;config.words[1]=WfcUtility_GetMessageText(WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage,0);config.words[2]=WfcUtility_GetMessageText(WfcUtilityCreateSlidingDialog_UnknownRoleZeroInitializedStorage,1);config.status=Ov031_GetStatusCode();Wireless_InitializeDownloadSessionContext(WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage,&config);if(!Network_ResetCommandForAcceptedStates())DisableInterruptsAndHaltForever();*(void**)(WfcUtilityUpdateConnectionAndDispatchEvents_UnknownRoleZeroInitializedStorage+0x1e29c)=WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_UpdateConnectionAndDispatchEvents,0,120);}

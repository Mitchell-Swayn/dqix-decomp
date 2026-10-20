#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e588; symbol: data_ov031_0224e588.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern volatile unsigned* YssdClientRunWorker_UnknownRoleZeroInitializedStorage;void YssdClient_SetWorkerPhase(unsigned);void System_AdvanceReadyStateOrSleep();void YssdClient_Authenticate();void YssdClient_LookupService();void YssdClient_ConnectSocket();void YssdClient_CloseSocket();void Network_SendNamedRequestAndHandleResponse();void YssdClient_ReceivePackets();}
// Original: arm9/ov031 @ 0x02210674; symbol: DrainSharedStateHandlersOneThroughSeven; size: 0xac.
// Drains shared state through handlers1-7 until state becomes zero.
extern "C" void YssdClient_RunWorker(){if(!YssdClientRunWorker_UnknownRoleZeroInitializedStorage)return;YssdClient_SetWorkerPhase(1);if(!*YssdClientRunWorker_UnknownRoleZeroInitializedStorage)return;do{switch(*YssdClientRunWorker_UnknownRoleZeroInitializedStorage){case 0:break;case 1:System_AdvanceReadyStateOrSleep();break;case 2:YssdClient_Authenticate();break;case 3:YssdClient_LookupService();break;case 4:YssdClient_ConnectSocket();break;case 5:YssdClient_CloseSocket();break;case 6:Network_SendNamedRequestAndHandleResponse();break;case 7:YssdClient_ReceivePackets();break;}}while(*YssdClientRunWorker_UnknownRoleZeroInitializedStorage);}

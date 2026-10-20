#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x20f2298; symbol: data_020f2298.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 48e10c02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
typedef void(*Handler)();extern "C" Handler CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords;extern "C" void IPC_WaitForPendingCommandCompletion();extern "C" void IPC_WaitForPendingCommandsAndRetryWithDelays();extern "C" void IPC_SendTwoWordCommandAndStoreCallbackState(int,int,int,void*,void*);
// Original: arm9/main @ 0x020CE704; symbol: func_020ce704; size: 0x54.
extern "C" void IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(void* a,void* b){Handler saved=CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords;CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords=IPC_WaitForPendingCommandCompletion;IPC_WaitForPendingCommandsAndRetryWithDelays();CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords=saved;IPC_SendTwoWordCommandAndStoreCallbackState(14,0,0,a,b);}

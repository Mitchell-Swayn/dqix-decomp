#include <globaldefs.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
// Original data: arm9/main @ 0x20f2298; symbol: data_020f2298.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 48e10c02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(void(*)(),int*);extern "C" void PowerManagement_StoreCommandResultCallback();extern "C" void IPC_PollPendingReplyWhenInterruptsUnavailable();extern "C" void PowerManagement_WaitForCommandCompletion();extern "C" void (*CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords)();
// Original: arm9/main @ 0x020CE758; symbol: func_020ce758; size: 0x4C.
extern "C" int PowerManagement_RunSynchronousOperationWithTemporaryCallback(){int out;int result=IPC_TemporarilyReplaceWaitHandlerAndSendCommandFourteen(PowerManagement_StoreCommandResultCallback,&out);if(result)return result;void (*callback)()=(void(*)())IPC_PollPendingReplyWhenInterruptsUnavailable;CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords=callback;callback();CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords=PowerManagement_WaitForCommandCompletion;return out;}

#include <globaldefs.h>
// Original data: arm9/main @ 0x20f2298; symbol: data_020f2298.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 48e10c02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int PowerManagement_StoreCommandResultCallback();extern "C" int IPC_SendTwoWordCommandAndStoreCallbackState(int,int,int,int(*)(),int*);extern "C" void (*CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords)();
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CE56C; symbol: func_020ce56c; size: 0x44.
extern "C" ARM int PowerManagement_ExecuteCommandSynchronously(int a,int b,int c){int result;int status=IPC_SendTwoWordCommandAndStoreCallbackState(a,b,c,PowerManagement_StoreCommandResultCallback,&result);if(status==0){CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords();return result;}return status;}

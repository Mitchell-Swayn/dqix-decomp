#include <globaldefs.h>
// Original data: arm9/main @ 0x20f2298; symbol: data_020f2298.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 48e10c02.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int PowerManagement_StoreCommandResultCallback();extern "C" void(*CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords)();extern "C" int PowerManagement_SetSelectedDeviceEnabled(int,int,int(*)(),int*);
#pragma optimization_level 4
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CE6D0; symbol: func_020ce6d0; size: 0x34.
extern "C" ARM int PowerManagement_SetDeviceEnabledSynchronously(int a,int b){int value;int result=PowerManagement_SetSelectedDeviceEnabled(a,b,PowerManagement_StoreCommandResultCallback,&value);if(result)return result;CalendarConvertValidatedDateToDayCount_UnknownRoleProcedureReferenceRecords();return value;}

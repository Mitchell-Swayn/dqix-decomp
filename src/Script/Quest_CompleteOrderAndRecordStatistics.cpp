#include <globaldefs.h>
extern "C" void* GameState_GetSerializedProgressState();extern "C" void Script_SetBoundedEntryStateComplete(void*,int);extern "C" void Quest_RemoveActiveEntryById(void*,int);extern "C" void Quest_RecordOrderCompletion(void*,int);
// Original: arm9/main @ 0x02095CFC; symbol: func_02095cfc; size: 0x34.
extern "C" ARM void Quest_CompleteOrderAndRecordStatistics(void* p,int value){Script_SetBoundedEntryStateComplete(GameState_GetSerializedProgressState(),value);Quest_RemoveActiveEntryById(p,value);Quest_RecordOrderCompletion(p,value);}

#include <globaldefs.h>
extern "C" void* Quest_GetGlobalOrderState();
extern "C" unsigned Script_ReadParameterAsInteger(unsigned);
extern "C" unsigned* Quest_FindActiveEntryById(void*,unsigned);
// Original: arm9/main @ 0x0209D260; symbol: func_0209d260; size: 0x48.
extern "C" bool Script_MarkQuestRecordWithFlag4000(unsigned value) {void* p=Quest_GetGlobalOrderState();if(!p)return false;unsigned* result=Quest_FindActiveEntryById(p,Script_ReadParameterAsInteger(value));if(!result)return false;*result|=0x4000;return true;}

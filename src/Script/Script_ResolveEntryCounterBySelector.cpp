#include <globaldefs.h>
extern "C" void* Quest_GetGlobalOrderState(void*); extern "C" char* Quest_FindActiveEntryById(void*,unsigned);
// Original: arm9/main @ 0x02064904; symbol: func_02064904; size: 0xAC.
extern "C" char* Script_ResolveEntryCounterBySelector(void* self,unsigned id,unsigned selector) { void* state=Quest_GetGlobalOrderState(self);char* record=Quest_FindActiveEntryById(state,id);char* result=0;if(record)switch(selector) { case 0:result=record+10;break;case 1:result=record+10;break;case 2:result=record+12;break;case 3:result=record+14;break;case 4:result=record+4;break;case 5:result=record+6;break;case 6:result=record+8;break;case 7:result=record+10;break;case 8:result=record+12;break;case 9:result=record+14;break;}return result; }

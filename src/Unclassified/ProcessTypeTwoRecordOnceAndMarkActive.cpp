#include <globaldefs.h>
ARM
extern "C" void* Object_GetGlobalSixteenEntryDisplayState(); extern "C" void InvokeHandlerForKeyedLinkedNode(void*, unsigned, unsigned); struct State { unsigned pad[2]; unsigned value; unsigned padc; unsigned type; unsigned char active; };
// Original: arm9/main @ 0x020DBFA4; symbol: func_020dbfa4; size: 0x3C.
 extern "C" void ProcessTypeTwoRecordOnceAndMarkActive(State* p,unsigned value) { if(p->type==2 && p->active==0) { InvokeHandlerForKeyedLinkedNode(Object_GetGlobalSixteenEntryDisplayState(),p->value,value); p->active=1; }}

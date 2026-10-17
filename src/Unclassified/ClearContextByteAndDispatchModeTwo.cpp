#include <globaldefs.h>
extern "C" void *Object_GetGlobalConnectionState(void); extern "C" int IsFirstWordNonzero(void *); extern "C" int TestInactiveOrPrimaryIndexState(void *); extern "C" void ClearContextEnabledByte1Bit(void *,int); extern "C" void Network_QueuePartyAction(int,int);
// Original: arm9/main @ 0x020E3798; symbol: func_020e3798; size: 0x50.
 extern "C" void ClearContextByteAndDispatchModeTwo(unsigned char *p) { void *q=Object_GetGlobalConnectionState(); if(!IsFirstWordNonzero(q)) return; p[2]=0; if(TestInactiveOrPrimaryIndexState(q)) ClearContextEnabledByte1Bit(p,0); else Network_QueuePartyAction(2,0); }

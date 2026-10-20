#include <globaldefs.h>
extern "C" void *Network_GetConnectionManager(void); extern "C" int Network_IsSessionActive(void *); extern "C" int Network_IsParentOrOffline(void *); extern "C" void Network_ClearPartySynchronizationAcknowledgement(void *,int); extern "C" void Network_QueuePartyAction(int,int);
// Original: arm9/main @ 0x020E3798; symbol: func_020e3798; size: 0x50.
 extern "C" void Network_ResetLocalPartySynchronization(unsigned char *p) { void *q=Network_GetConnectionManager(); if(!Network_IsSessionActive(q)) return; p[2]=0; if(Network_IsParentOrOffline(q)) Network_ClearPartySynchronizationAcknowledgement(p,0); else Network_QueuePartyAction(2,0); }

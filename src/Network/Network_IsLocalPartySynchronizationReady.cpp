#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(void*);
// Original: arm9/main @ 0x020E37E8; symbol: func_020e37e8; size: 0x20.
extern "C" unsigned Network_IsLocalPartySynchronizationReady(unsigned char* p){return Network_IsSessionActive(Network_GetConnectionManager())?p[2]:1;}

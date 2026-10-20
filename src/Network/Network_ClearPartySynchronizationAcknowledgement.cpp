#include <globaldefs.h>
ARM
extern "C" void* Network_GetConnectionManager();extern "C" int Network_IsSessionActive(void*);
// Original: arm9/main @ 0x020E3748; symbol: func_020e3748; size: 0x30.
extern "C" void Network_ClearPartySynchronizationAcknowledgement(unsigned char* p,int bit){if(Network_IsSessionActive(Network_GetConnectionManager()))p[1]&=~(1U<<bit);}

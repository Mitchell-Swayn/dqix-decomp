#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *Network_GetConnectionManager();int Network_IsSessionActive(void *);
// Original: arm9/main @ 0x020E3368; symbol: func_020e3368; size: 0x4C.
void NetworkOwnership_QueueRequest(unsigned char *p,unsigned char v){if(!Network_IsSessionActive(Network_GetConnectionManager()))return;unsigned char *q=p+32;for(int i=0;i<8;i++,q++)if(!*q){*q=v;return;}}
}

#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void *Network_GetConnectionManager();int Network_IsSessionActive(void *);
// Original: arm9/main @ 0x020E30A4; symbol: func_020e30a4; size: 0x4C.
unsigned char *NetworkOwnership_FindFreeEntry(unsigned char *p){if(!Network_IsSessionActive(Network_GetConnectionManager()))return 0;for(int i=0;i<8;p+=4,i++)if(!p[2])return p;return 0;}
}

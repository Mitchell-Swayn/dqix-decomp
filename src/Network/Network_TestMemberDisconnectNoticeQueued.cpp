#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
int Network_FindWirelessSlotByMemberId(void *);
// Original: arm9/main @ 0x0202C758; symbol: func_0202c758; size: 0x20.
unsigned int Network_TestMemberDisconnectNoticeQueued(unsigned char *p){int i=Network_FindWirelessSlotByMemberId(p);return p[0x1010]&(1u<<i);}
}

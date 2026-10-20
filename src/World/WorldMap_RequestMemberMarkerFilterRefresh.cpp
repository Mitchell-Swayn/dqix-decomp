#include <globaldefs.h>

// Original: arm9/main @ 0x02026BC8; symbol: func_02026bc8; size: 0x14.
extern "C" ARM void WorldMap_RequestMemberMarkerFilterRefresh (unsigned char* p, unsigned int n) { p[0xa96] |= 1 << n; }

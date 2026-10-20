#include <globaldefs.h>
ARM
extern "C" int Network_ResolveIpv4Host(void*);
// Original: arm9/ov031 @ 0x02217F9C; symbol: func_ov031_02217f9c; size: 0x14.
extern "C" int HttpDownload_ResolveRequestHost(void* p) { return Network_ResolveIpv4Host(*(void**)((char*)p + 0x1124)); }

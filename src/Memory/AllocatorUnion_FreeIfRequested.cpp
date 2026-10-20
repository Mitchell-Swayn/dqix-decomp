#include <globaldefs.h>
ARM
extern "C" void _ZN14AllocatorUnion4FreeEPv(void*,void*);
// Original: arm9/main @ 0x02012DBC; symbol: func_02012dbc; size: 0x14.
extern "C" void AllocatorUnion_FreeIfRequested(void* allocator,void* data,int release){if(!release)return;_ZN14AllocatorUnion4FreeEPv(allocator,data);}

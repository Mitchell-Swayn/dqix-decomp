#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
extern "C" {
extern unsigned int *data_021142c0;
// Original: arm9/main @ 0x020D2A20; symbol: func_020d2a20; size: 0x28.
unsigned int InvalidateAndReadSharedWord(){InvalidateDataCacheRange(data_021142c0,4);return *data_021142c0;}
}

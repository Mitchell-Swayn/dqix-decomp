#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
extern "C" {
extern unsigned int *data_021142c0;
// Original: arm9/main @ 0x020D29F4; symbol: func_020d29f4; size: 0x2C.
unsigned int SoundCommand_ReadInvalidatedSharedStatus(){InvalidateDataCacheRange(data_021142c0+1,4);return data_021142c0[1];}
}

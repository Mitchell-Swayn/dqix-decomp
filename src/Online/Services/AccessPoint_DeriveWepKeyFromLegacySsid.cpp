#include <globaldefs.h>
ARM
extern "C" int AccessPoint_MixLegacySsidPayloadIntoWepKey(void*);
// Original: arm9/ov031 @ 0x022157E8; symbol: func_ov031_022157e8; size: 0x10.
extern "C" int AccessPoint_DeriveWepKeyFromLegacySsid(void* p) { return AccessPoint_MixLegacySsidPayloadIntoWepKey((char*)p + 0xc); }

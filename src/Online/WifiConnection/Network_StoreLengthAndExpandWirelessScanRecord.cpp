#include <globaldefs.h>
THUMB
extern "C" int Network_ExpandWirelessScanRecord(void*, void*, unsigned int);
// Original: arm9/ov031 @ 0x0221E798; symbol: func_ov031_0221e798; size: 0x10.
extern "C" int Network_StoreLengthAndExpandWirelessScanRecord(void* p, void* a, unsigned int v) { *(unsigned int*)p = v; return Network_ExpandWirelessScanRecord(a, (char*)p + 4, v); }

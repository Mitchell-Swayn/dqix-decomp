#include <globaldefs.h>
extern "C" unsigned data_ov001_02165800;
// Original: arm9/ov001 @ 0x021536E0; symbol: func_ov001_021536e0; size: 0x1C.
extern "C" ARM int IncrementOverlayReferenceCounter() { ++data_ov001_02165800; return 1; }

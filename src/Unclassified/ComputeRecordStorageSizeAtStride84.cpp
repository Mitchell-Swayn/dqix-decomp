#include <globaldefs.h>
ARM
struct Bits { unsigned int count:12; unsigned int rest:20; };
// Original: arm9/main @ 0x02070AF4; symbol: func_02070af4; size: 0x18.
 extern "C" unsigned int ComputeRecordStorageSizeAtStride84(Bits* p) { return p->count*0x84; }

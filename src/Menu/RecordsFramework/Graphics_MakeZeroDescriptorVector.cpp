#include <globaldefs.h>
ARM
extern "C" void* __clear(void*,unsigned);
struct Vector {int x,y,z;};
// Original: arm9/ov023 @ 0x021F8C1C; symbol: func_ov023_021f8c1c; size: 0x2C.
// Returns a zero vector through the aggregate-return ABI.
extern "C" Vector Graphics_MakeZeroDescriptorVector(){Vector result;__clear(&result,12);return result;}

#include <globaldefs.h>
extern "C" signed char* data_ov031_02250ba8;
// Stores the input byte in the shared object at offset 0x16.
// Original: arm9/ov031 @ 0x02222E40; symbol: func_ov031_02222e40; size: 0x14.
extern "C" ARM void SetSharedByteAtOffset16(signed char value)
{
    data_ov031_02250ba8[0x16] = value;
}

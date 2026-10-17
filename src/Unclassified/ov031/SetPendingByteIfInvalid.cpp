#include <globaldefs.h>
extern "C" {
extern signed char* data_ov031_02250ba8;
}
// Original: arm9/ov031 @ 0x02222E20; symbol: func_ov031_02222e20; size: 0x20.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void SetPendingByteIfInvalid(signed char value)
{
    signed char* p=data_ov031_02250ba8;
    if(p[0x16]==-1) p[0x16]=value;
}

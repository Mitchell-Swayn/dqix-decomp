#include <globaldefs.h>
extern "C" {
extern char* data_ov031_02290cf4;
}
// Original: arm9/ov031 @ 0x0223521C; symbol: func_ov031_0223521c; size: 0x18.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void SetStateByteAt1E(void)
{
    data_ov031_02290cf4[0x1e]=1;
}

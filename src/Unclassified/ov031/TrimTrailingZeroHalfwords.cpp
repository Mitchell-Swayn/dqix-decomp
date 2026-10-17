#include <globaldefs.h>

// Original: arm9/ov031 @ 0x0220BB24; symbol: func_ov031_0220bb24; size: 0x28.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int TrimTrailingZeroHalfwords(unsigned short* p, int n)
{
    while(n != 0 && ((unsigned short*)((char*)p+n*2))[-1] == 0) --n;
    return n;
}

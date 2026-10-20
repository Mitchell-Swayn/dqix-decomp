#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02160FD4; symbol: func_ov000_02160fd4; size: 0x10.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM unsigned BattleScene_GetMaskedFlags(char* p, unsigned mask)
{
    return *(unsigned*)(p+0x55f4) & mask;
}

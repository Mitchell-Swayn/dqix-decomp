#include <globaldefs.h>
// Original: arm9/ov024 @ 0x021EB4B0; symbol: func_ov024_021eb4b0; size: 0x34.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM int Combat_CanReplaceAilmentFlags(void* object, unsigned int flags, unsigned int mask)
{
    if (flags & 8) return 0;
    if (flags & 16) return 0;
    if (flags & 0x80000) return 0;
    return (flags & mask) == 0;
}

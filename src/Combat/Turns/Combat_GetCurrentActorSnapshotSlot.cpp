#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0215E918; symbol: func_ov000_0215e918; size: 0x20.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM void* Combat_GetCurrentActorSnapshotSlot(void* object)
{
    unsigned char* p = (unsigned char*)object;
    unsigned int index = p[0x8e00];
    if (index >= 72) return 0;
    return p + 0x20 + index * 52;
}

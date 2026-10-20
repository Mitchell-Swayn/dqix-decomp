#include <globaldefs.h>
// Original: arm9/ov000 @ 0x0215E9D8; symbol: func_ov000_0215e9d8; size: 0x24.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM void* Combat_GetCurrentCommandSlot(void* object)
{
    unsigned char* p = (unsigned char*)object;
    int index = *(int*)(p + 0x8e24);
    if (index >= 72) return 0;
    return p + 0x821c + index * 40;
}

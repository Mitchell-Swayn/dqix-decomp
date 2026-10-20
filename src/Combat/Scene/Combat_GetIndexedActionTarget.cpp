#include <globaldefs.h>
// Original: arm9/ov000 @ 0x021600F8; symbol: func_ov000_021600f8; size: 0x38.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM void* Combat_GetIndexedActionTarget(void* object, int index)
{
    unsigned char* p = (unsigned char*)object;
    if (p[9] <= index) return 0;
    void* node = *(void**)(p + 20);
    int i = 0;
    while (i < index && node)
    {
        node = *(void**)((unsigned char*)node + 32);
        ++i;
    }
    return node;
}

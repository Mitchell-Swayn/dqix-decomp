#include <globaldefs.h>
// Original: arm9/ov000 @ 0x02160094; symbol: func_ov000_02160094; size: 0x38.
// Field roles are unresolved; offsets describe the observed layout.
extern "C" ARM void* GetPrimaryLinkedRecordByIndex(void* object, int index)
{
    unsigned char* p = (unsigned char*)object;
    if (p[8] <= index) return 0;
    void* node = *(void**)(p + 16);
    int i = 0;
    while (i < index && node)
    {
        node = *(void**)((unsigned char*)node + 48);
        ++i;
    }
    return node;
}

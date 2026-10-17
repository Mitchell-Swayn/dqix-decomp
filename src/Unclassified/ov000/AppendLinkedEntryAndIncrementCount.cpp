#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0215FE84; symbol: func_ov000_0215fe84; size: 0x30.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void AppendLinkedEntryAndIncrementCount(char* p, void* entry, int index)
{
    void** slot = (void**)(p + index*4);
    while (*slot) slot = (void**)((char*)*slot + 0x20);
    *slot = entry;
    unsigned char* counts=(unsigned char*)p+0x26;
    counts[index] = (unsigned char)(counts[index] + 1);
}

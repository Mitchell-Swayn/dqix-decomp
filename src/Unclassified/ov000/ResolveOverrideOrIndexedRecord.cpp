#include <globaldefs.h>

// Original: arm9/ov000 @ 0x02160F20; symbol: func_ov000_02160f20; size: 0x40.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM char* ResolveOverrideOrIndexedRecord(char* p)
{
    char* base=*(char**)(p+0x29c);
    if(!base) return 0;
    char* override=*(char**)(p+0x770c);
    if(!override) override=base+0x821c+*(int*)(p+0x55d8)*0x28;
    return override;
}

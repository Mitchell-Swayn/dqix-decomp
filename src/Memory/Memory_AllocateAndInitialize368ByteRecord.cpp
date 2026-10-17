#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
#pragma optimize_for_size off
extern "C" void ResetRecordCountersFlagsAndThreeVectorBuffers(int);

// Original: arm9/main @ 0x020556DC; symbol: func_020556dc; size: 0x3C.
extern "C" int Memory_AllocateAndInitialize368ByteRecord(int *out, unsigned int size) {
    if (size == 0) {
        return 0;
    }
    *out = (int)((SafeAllocator *)size)->Allocate(0x170);
    if (*out == 0) {
        return 0;
    }
    ResetRecordCountersFlagsAndThreeVectorBuffers(*out);
    return 1;
}

#include <globaldefs.h>

extern "C" int CountAllocatorEntriesWithKindOneAndMatchingId(int);
struct Owner { char unknown[0xb8]; short id; };

// Original: arm9/main @ 0x0209C6BC; symbol: func_0209c6bc; size: 0x1C.
extern "C" ARM bool Sound_HasTypeOneJobForOwnerId(Owner* object) {
    return CountAllocatorEntriesWithKindOneAndMatchingId(object->id) != 0;
}

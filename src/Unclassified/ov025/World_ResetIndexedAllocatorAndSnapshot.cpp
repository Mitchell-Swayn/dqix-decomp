#include <globaldefs.h>
ARM
extern "C" void _ZN13SafeAllocator5ResetEv(void *);
extern "C" void SnapshotBlockAndVolatileWordPair(char *);
extern "C" void func_ov025_021e8bc4(void *, unsigned int);
// Original: arm9/ov025 @ 0x021E8B6C; symbol: func_ov025_021e8b6c; size: 0x38.
extern "C" void World_ResetIndexedAllocatorAndSnapshot(void *state) {
    volatile unsigned char *bytes = (volatile unsigned char *)state;
    _ZN13SafeAllocator5ResetEv(*(void **)((char *)state + bytes[0x30] * 4 + 0x10));
    SnapshotBlockAndVolatileWordPair((char *)*(void **)((char *)state + bytes[0x30] * 4 + 0x20));
    func_ov025_021e8bc4(state, bytes[0x30]);
}

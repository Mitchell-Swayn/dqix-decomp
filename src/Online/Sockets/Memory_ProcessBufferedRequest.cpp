#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Memory_ReserveBufferedCapacity(unsigned size, void* state);
extern "C" void ConsumeBufferBytesAndNotify(unsigned size, void* state);
// Original: arm9/ov031 @ 0x02203670; symbol: func_ov031_02203670; size: 0x38.
extern "C" void Memory_ProcessBufferedRequest(unsigned size) {
    unsigned char* global = *(unsigned char**)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
    unsigned char* state = *(unsigned char**)(global + 0xA4);
    if (state == 0) return;
    if (*(unsigned char*)(state + 9) != 0)
        Memory_ReserveBufferedCapacity(size, state);
    else
        ConsumeBufferBytesAndNotify(size, state);
}

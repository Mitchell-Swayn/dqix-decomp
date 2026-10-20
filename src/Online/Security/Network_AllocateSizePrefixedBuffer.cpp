#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e234; symbol: data_ov031_0224e234.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage[];
typedef void *(*AllocateWithContext)(int, void *);
// Original: arm9/ov031 @ 0x022075F4; symbol: Unclassified_AllocateRecordAndPrefixPayloadPointer; size: 0x2C.
// Calls the global allocator with input+4, stores that pointer at the returned record, and returns record+4 when allocation succeeds.
extern "C" void *Network_AllocateSizePrefixedBuffer(void *p) {
    void *value = (char *)p + 4;
    AllocateWithContext allocate = *(AllocateWithContext *)(NetworkSocketGetHostByName_UnknownRoleZeroInitializedStorage + 0xc);
    void *result = allocate(0, value);
    if (result) {
        *(void **)result = value;
        result = (char *)result + 4;
    }
    return result;
}

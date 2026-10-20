#include <globaldefs.h>
ARM
extern "C" void* Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" unsigned int WfcUtility_CreateSteppedPointerRing(unsigned, void*, unsigned);
// Original data: arm9/ov031 @ 0x2290c40; symbol: data_ov031_02290c40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile unsigned int WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022275E0; symbol: System_AllocateGlobalResourceObject; size: 0x3C.
// Allocates a 0x64-byte object, stores it globally, creates its resource, and saves it at +0x60.
extern "C" void System_AllocateGlobalResourceObject(void) {
    void* object = Memory_AllocateZeroedBlock(0x64, 4);
    WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[0] = (unsigned int)object;
    unsigned int value = WfcUtility_CreateSteppedPointerRing(8, object, 0xC);
    void* stored = (void*)WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[0];
    *(unsigned int*)((char*)stored + 0x60) = value;
}

#include <globaldefs.h>
ARM
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(unsigned int value);
extern "C" void PushPointerIntoInterruptProtectedRing(void *context, void *object);
// Original data: arm9/ov031 @ 0x2290c40; symbol: data_ov031_02290c40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char *WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02227688; symbol: func_ov031_02227688; size: 0x2C.
extern "C" void System_UpdateObjectAndGlobalContext(void *object) {
    WfcUtility_FreeArchiveResourceAndReturnPoolEntry(*(unsigned int *)((char *)object + 8));
    void *context = *(void **)((char *)WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[0] + 0x60);
    PushPointerIntoInterruptProtectedRing(context, object);
}

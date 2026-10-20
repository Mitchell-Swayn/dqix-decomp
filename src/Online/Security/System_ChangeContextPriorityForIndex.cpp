#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void _Z21ChangeContextPriorityP16ProcessorContextj(void *, unsigned int);
// Original: arm9/ov031 @ 0x02207D3C; symbol: func_ov031_02207d3c; size: 0x24.
extern "C" void System_ChangeContextPriorityForIndex(unsigned int index) {
    if (index < 0x20)
        _Z21ChangeContextPriorityP16ProcessorContextj(*(void **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4), index);
}

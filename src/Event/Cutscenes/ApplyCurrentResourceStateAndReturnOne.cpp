#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage[];
extern "C" void ResourceHandle_ApplyAndSaveCurrentState(void *);
// Original: arm9/ov001 @ 0x02163994; symbol: func_ov001_02163994; size: 0x18.
extern "C" int ApplyCurrentResourceStateAndReturnOne(void) {
    ResourceHandle_ApplyAndSaveCurrentState(Main_UnknownRoleZeroInitializedStorage);
    return 1;
}

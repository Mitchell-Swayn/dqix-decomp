#include <globaldefs.h>
#include "Resource/Script.h"

// Original data: arm9/main @ 0x2109be0; symbol: data_02109be0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char BgmGetGlobalZoneOverrideTable_UnknownRoleZeroInitializedStorage[];
extern "C" void AllocatePositiveWordArrayAndStoreByteCount(void* result, int value);

// Original: arm9/main @ 0x0209CB74; symbol: func_0209cb74; size: 0x20.
extern "C" int Script_AllocateGlobalListByIntegerParameter(Script::Parameter* parameter)
{
    int value = parameter->ToInt();
    AllocatePositiveWordArrayAndStoreByteCount(BgmGetGlobalZoneOverrideTable_UnknownRoleZeroInitializedStorage, value);
    return 1;
}

#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" int Object_ReadIdValueWithZoneRemapAndOverride(int);
extern "C" ARM void ResourceHandle_SwitchTargetUnlessBlocked(void *, int);
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[];
// Original: arm9/ov001 @ 0x02163AEC; symbol: Script_SwitchResourceTargetFromRemappedGlobalId; size: 0x28.
// Reads the global halfword ID, applies object zone remapping/override, and switches the target for data_02109BF4.
extern "C" int Script_SwitchResourceTargetFromRemappedGlobalId(void) {
    int id = *(unsigned short *)Zone3D_GetMainInstance();
    int target = Object_ReadIdValueWithZoneRemapAndOverride(id);
    ResourceHandle_SwitchTargetUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2, target);
    return 1;
}

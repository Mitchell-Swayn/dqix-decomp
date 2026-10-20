#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" void WorldMap_ReallocateTaggedMarkerCoordinates(int, int);
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0201F390; symbol: func_0201f390; size: 0x24.
extern "C" int Script_DispatchIntegerToStoredTarget(Script::Parameter* parameter) {
    int value=parameter->ToInt();
    int target=PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[4];
    WorldMap_ReallocateTaggedMarkerCoordinates(target,value);
    return 1;
}

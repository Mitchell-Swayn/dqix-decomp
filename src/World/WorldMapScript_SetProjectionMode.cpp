#include "Resource/Script.h"

struct UnknownPointerSlot
{
    unsigned char unknown_00[0x10];
    void* state;
};
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern UnknownPointerSlot PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage;

// The literal names a global slot containing a pointer; the pointed record's
// field at offset 0x14 has no established semantic name.
// Original: arm9/main @ 0x0201F844; symbol: func_0201f844; size: 0x20.
extern "C" int WorldMapScript_SetProjectionMode(Script::Parameter* parameter)
{
    int value = parameter->ToInt();
    *(int*)((unsigned char*)PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage.state + 0x14) = value;
    return 1;
}

#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void Field_ApplyMemberWeaponAttachmentVariant(int index, int enabled);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
struct PlacementEntry { int kind; unsigned value; unsigned flags; unsigned reserved; };
// Original: arm9/ov001 @ 0x02160938; symbol: func_ov001_02160938; size: 0x68.
// Applies an indexed placement variant when the selected entry has an accepted kind.
extern "C" int Script_ApplyIndexedObjectPlacementVariant(IntegerParameterView *parameters) {
    int index = Script_ReadParameterAsInteger(parameters);
    int enabled = Script_ReadParameterAsInteger((IntegerParameterView *)((char *)parameters + 8));
    PlacementEntry *entries = *(PlacementEntry **)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4);
    if (entries[index].kind != 4 && entries[index].kind != 0 && entries[index].kind != 5) return 0;
    if (enabled) Field_ApplyMemberWeaponAttachmentVariant((int)entries[index].value, 1);
    else Field_ApplyMemberWeaponAttachmentVariant((int)entries[index].value, 0);
    return 1;
}

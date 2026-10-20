#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d8498; symbol: data_ov017_021d8498.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1448 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char FieldApplyMonsterSnapshotVariant_UnknownRoleZeroInitializedStorage[];
extern "C" int Field_UpsertMonsterDescriptorFragment(void*, void*);
extern "C" int Field_UpsertMonsterTransformFragment(void*, void*);
struct RecordTag { unsigned char type:2; };
// Original: arm9/ov017 @ 0x021C912C; symbol: func_ov017_021c912c; size: 0x3C.
extern "C" int Field_ApplyMonsterSnapshotVariant(void* unused, void* record) {
    unsigned type = ((RecordTag*)((char*)record + 4))->type;
    void* global = FieldApplyMonsterSnapshotVariant_UnknownRoleZeroInitializedStorage;
    if (type == 0)
        return Field_UpsertMonsterDescriptorFragment(global, (char*)record + 6);
    if (type == 1)
        return Field_UpsertMonsterTransformFragment(global, (char*)record + 6);
    return (int)global;
}

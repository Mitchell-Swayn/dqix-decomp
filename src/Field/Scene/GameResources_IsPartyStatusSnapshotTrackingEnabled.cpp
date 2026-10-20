#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d82e0; symbol: data_ov017_021d82e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned char FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage[];
extern "C" bool PartyStatus_IsSnapshotTrackingEnabled(unsigned char *p, int i);
// Original: arm9/ov017 @ 0x0218B628; symbol: func_ov017_0218b628; size: 0x3C.
extern "C" int GameResources_IsPartyStatusSnapshotTrackingEnabled(int index) {
    unsigned char *base = *(unsigned char **)(FieldRunSceneLifecycle_UnknownRoleZeroInitializedStorage + 4);
    if (base == 0) {
        return 0;
    }
    unsigned char *field = *(unsigned char **)(base + 0x36D0);
    if (field == 0) {
        return 0;
    }
    return PartyStatus_IsSnapshotTrackingEnabled(field, index);
}

#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d83ac; symbol: data_ov017_021d83ac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" void *FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
extern "C" int Network_AllocateAndEnqueueTypeNinetyFourNode(void *, int);
// Original: arm9/ov017 @ 0x021A5A68; symbol: func_ov017_021a5a68; size: 0x20.
extern "C" void Script_CallWithGlobalParameterIfPresent(int unused, int value) {
    void *parameter = FieldMenuUpdatePartyMenuOverlay_UnknownRoleZeroInitializedStorage;
    if (parameter != 0)
        Network_AllocateAndEnqueueTypeNinetyFourNode(parameter, value);
}

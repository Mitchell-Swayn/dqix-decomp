#include <globaldefs.h>
ARM
extern "C" void **FindLinkFieldForNode(void **head, void *target);
// Original data: arm9/ov031 @ 0x224e230; symbol: data_ov031_0224e230.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022071B4; symbol: Util_GlobalNodeListContainsTarget; size: 0x24.
// Returns whether the target node is present in the global linked list.
extern "C" int Util_GlobalNodeListContainsTarget(int value) {
    return FindLinkFieldForNode((void **)NetworkDestroyClosedSockets_UnknownRoleZeroInitializedStorage, (void *)value) != 0;
}

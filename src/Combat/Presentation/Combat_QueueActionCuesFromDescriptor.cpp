#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" void Combat_QueueActionResultEffectDescriptors(void *, int, int);
// Original: arm9/ov025 @ 0x021E6230; symbol: TransformGlobalRecordAtOffset540; size: 0x24.
// Passes the global record at +0x540 and the second and fourth arguments to its transformer.
extern "C" int Combat_QueueActionCuesFromDescriptor(int unused0, int second, int unused2, int fourth) {
    void *object = *(void **)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0x0c);
    Combat_QueueActionResultEffectDescriptors((unsigned char *)object + 0x540, second, fourth);
    return 1;
}

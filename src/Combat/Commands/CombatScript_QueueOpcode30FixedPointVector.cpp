#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void _ZN6Script9Parameter9ToVec3fixEP8Vector3i(void *, void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216B26C; symbol: Memory_QueueScriptVector3Record30; size: 0x50.
// Allocates a 20-byte entry, tags it 0x30, converts the script parameter to fixed-point Vec3 at +8, submits it, and returns success.
extern "C" int CombatScript_QueueOpcode30FixedPointVector(void *parameter) {
    char *entry = _ZN13SafeAllocator8AllocateEj(*(unsigned int *)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0x14);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x30;
    _ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter, entry + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}

#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
extern "C" void Queue_AppendType6Node(void *);
// Original: arm9/ov001 @ 0x0215D768; symbol: func_ov001_0215d768; size: 0x1C.
extern "C" unsigned Script_QueueCameraPathReset(void) {
    Queue_AppendType6Node(*(void **)((char *)EventGetObjectSession_UnknownRoleZeroInitializedStorage + 0x24));
    return 1;
}

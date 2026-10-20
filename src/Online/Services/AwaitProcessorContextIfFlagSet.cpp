#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x02216A84; symbol: func_ov031_02216a84; size: 0x30.
extern "C" void AwaitProcessorContextIfFlagSet(void) {
    unsigned char *base = *(unsigned char **)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage + 8);
    if (*(unsigned int *)(base + 0x1384) != 0)
        _Z22AwaitContextCompletionP16ProcessorContext(base + 0x1318);
}

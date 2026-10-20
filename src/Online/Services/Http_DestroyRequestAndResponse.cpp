#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290fc8; symbol: data_ov031_02290fc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char HttpDestroyRequest_UnknownRoleZeroInitializedStorage[];
extern "C" void Http_DestroyRequest(void *);
// Original: arm9/ov031 @ 0x02240DF4; symbol: func_ov031_02240df4; size: 0x28.
extern "C" void Http_DestroyRequestAndResponse(void *object) {
    ((void (*)(void *))(*(void **)HttpDestroyRequest_UnknownRoleZeroInitializedStorage))(*(void **)((unsigned char *)object + 0x30));
    Http_DestroyRequest(object);
}

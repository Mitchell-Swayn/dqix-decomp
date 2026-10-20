#include <globaldefs.h>
// Original data: arm9/main @ 0x210a010; symbol: data_0210a010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 612 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage[]; extern "C" void MI_Copy36B(void*,void*);
// Original: arm9/main @ 0x02016D8C; symbol: func_02016d8c; size: 0x28.
extern "C" void RenderConfig_CopyTransformAndClearFlagsA4(void* input) { MI_Copy36B(input,&RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage[47]); RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage[63] &= ~0xa4u; }

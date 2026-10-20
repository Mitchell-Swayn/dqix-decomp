#include <globaldefs.h>
ARM

struct ProcessorContext;
extern "C" int _Z17IsContextInactiveP16ProcessorContext(ProcessorContext *context);
extern "C" void System_MarkStateReadyAndAwaitContext(void *state);
// Original data: arm9/ov031 @ 0x224e69c; symbol: data_ov031_0224e69c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x0221A854; symbol: func_ov031_0221a854; size: 0x48.
extern "C" void System_UpdateContextWhenActive(void) {
    if (*(unsigned char **)(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage) == 0) return;
    if (*(void **)(*(unsigned char **)(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage) + 0x1bac) == 0) return;
    if (_Z17IsContextInactiveP16ProcessorContext((ProcessorContext *)(*(unsigned char **)(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage) + 0x1b40)) != 0) return;
    System_MarkStateReadyAndAwaitContext(*(unsigned char **)(NasServiceLocatorPollRequest_UnknownRoleZeroInitializedStorage) + 8);
}

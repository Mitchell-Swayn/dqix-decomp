#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage[];
extern "C" void System_MarkStateReadyAndAwaitContext(void *);
extern "C" void System_StopSharedWorkerAndAwaitContext(void);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x02219178; symbol: func_ov031_02219178; size: 0x68.
extern "C" void Ov031_FinalizePendingContextTransition(void) {
    if (*(void **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage == 0) return;
    if (*(void **)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage + 0x14) != 0) System_MarkStateReadyAndAwaitContext(*(void **)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage + 0x14));
    System_StopSharedWorkerAndAwaitContext();
    char *context = *(char **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
    if (*(void **)(context + 0x1188) != 0) _Z22AwaitContextCompletionP16ProcessorContext(context + 0x111c);
    *(int *)(*(char **)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage + 0x1004) = -7;
}

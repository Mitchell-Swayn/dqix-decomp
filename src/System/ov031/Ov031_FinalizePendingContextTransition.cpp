#include <globaldefs.h>
extern "C" char data_ov031_0224e60c[];
extern "C" void System_MarkStateReadyAndAwaitContext(void *);
extern "C" void System_StopSharedWorkerAndAwaitContext(void);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x02219178; symbol: func_ov031_02219178; size: 0x68.
extern "C" void Ov031_FinalizePendingContextTransition(void) {
    if (*(void **)data_ov031_0224e60c == 0) return;
    if (*(void **)(data_ov031_0224e60c + 0x14) != 0) System_MarkStateReadyAndAwaitContext(*(void **)(data_ov031_0224e60c + 0x14));
    System_StopSharedWorkerAndAwaitContext();
    char *context = *(char **)data_ov031_0224e60c;
    if (*(void **)(context + 0x1188) != 0) _Z22AwaitContextCompletionP16ProcessorContext(context + 0x111c);
    *(int *)(*(char **)data_ov031_0224e60c + 0x1004) = -7;
}

#include <globaldefs.h>
ARM

struct ProcessorContext;
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(ProcessorContext *context);
extern "C" void func_ov031_022127a8();
extern "C" ProcessorContext *data_ov031_0224e5c0;

// Original: arm9/ov031 @ 0x022128B8; symbol: func_ov031_022128b8; size: 0x44.
extern "C" void System_AwaitAndDispatchDeferredCallback(void) {
    ProcessorContext *context = data_ov031_0224e5c0;
    _Z22AwaitContextCompletionP16ProcessorContext((ProcessorContext *)((char *)context + 0x9c0));
    context = data_ov031_0224e5c0;
    void (*callback)(void) = *(void (**)(void))((char *)context + 4);
    func_ov031_022127a8();
    data_ov031_0224e5c0 = 0;
    if (callback != 0) callback();
}

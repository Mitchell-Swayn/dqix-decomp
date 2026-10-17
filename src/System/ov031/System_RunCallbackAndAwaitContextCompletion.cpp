#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_02290fd0;
extern "C" unsigned char data_ov031_022918dc;
extern "C" void func_ov031_022403f4(void);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(void *);
// Original: arm9/ov031 @ 0x022403B0; symbol: func_ov031_022403b0; size: 0x28.
extern "C" void System_RunCallbackAndAwaitContextCompletion(void) {
    data_ov031_02290fd0 = 1;
    func_ov031_022403f4();
    _Z22AwaitContextCompletionP16ProcessorContext(&data_ov031_022918dc);
}

#include <globaldefs.h>
ARM

struct Mutex;
struct ProcessorContext;
extern "C" void _Z9LockMutexP5Mutex(Mutex *mutex);
extern "C" void _Z11UnlockMutexP5Mutex(Mutex *mutex);
extern "C" void _Z22AwaitContextCompletionP16ProcessorContext(ProcessorContext *context);

// Original: arm9/ov031 @ 0x02217E70; symbol: func_ov031_02217e70; size: 0x5C.
extern "C" void System_MarkStateReadyAndAwaitContext(unsigned char *state) {
    if (state[0x1000] != 0xff) return;
    _Z9LockMutexP5Mutex((Mutex *)(state + 0x3f8 + 0x1800));
    *(unsigned int *)(state + 0x1000 + 0xc10) = 1;
    _Z11UnlockMutexP5Mutex((Mutex *)(state + 0x3f8 + 0x1800));
    if (*(void **)(state + 0x1000 + 0xba4) == 0) return;
    _Z22AwaitContextCompletionP16ProcessorContext((ProcessorContext *)(state + 0x338 + 0x1800));
}

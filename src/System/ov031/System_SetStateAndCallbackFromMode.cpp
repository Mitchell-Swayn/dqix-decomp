#include <globaldefs.h>
ARM
extern "C" void SetStateByteAt1E(void *);
extern "C" void System_QueueTimedCallbackForSharedRecord(int);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_0222f6ac(void);
// Original: arm9/ov031 @ 0x0222F68C; symbol: func_ov031_0222f68c; size: 0x20.
extern "C" void System_SetStateAndCallbackFromMode(void *state) {
    SetStateByteAt1E(state);
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_0222f6ac);
}

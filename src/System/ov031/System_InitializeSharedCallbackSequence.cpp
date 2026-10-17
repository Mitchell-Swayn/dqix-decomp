#include <globaldefs.h>
ARM

extern "C" void func_ov031_022277e4(void);
extern "C" void SetSharedByte18(void);
extern "C" void System_QueueTimedCallbackForSharedRecord(unsigned short);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_0222acc0(void);
extern "C" unsigned char data_ov031_02290c7c[];

// Original: arm9/ov031 @ 0x0222AC88; symbol: func_ov031_0222ac88; size: 0x38.
extern "C" void System_InitializeSharedCallbackSequence(void) {
    if (data_ov031_02290c7c[0] == 0) {
        func_ov031_022277e4();
    }
    SetSharedByte18();
    System_QueueTimedCallbackForSharedRecord(8);
    SetMainLoopCallback(func_ov031_0222acc0);
}

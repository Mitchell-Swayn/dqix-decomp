#include <globaldefs.h>
ARM

extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02237b2c(unsigned, unsigned, unsigned, int, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void RegisterCallbackWhenSharedObjectAbsent(void);

// Original: arm9/ov031 @ 0x02231008; symbol: func_ov031_02231008; size: 0x50.
extern "C" void System_InitializeActionWhenBothContextsClear(void) {
    if (ReadSelectedContextByte9(1) != 0) {
        return;
    }
    if (ReadSelectedContextByte9(0) != 0) {
        return;
    }
    func_ov031_02237b2c(0x44, 5, 1, -1, 0);
    SetMainLoopCallback(RegisterCallbackWhenSharedObjectAbsent);
}

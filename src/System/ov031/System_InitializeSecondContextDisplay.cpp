#include <globaldefs.h>
ARM

extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void func_ov031_02222ddc(void);
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void System_InstallCallbackWhenContextReady(void);

// Original: arm9/ov031 @ 0x02229D9C; symbol: func_ov031_02229d9c; size: 0x3C.
extern "C" void System_InitializeSecondContextDisplay(void) {
    if (ReadSelectedContextByte9(1) != 0) {
        return;
    }
    func_ov031_02222ddc();
    func_ov031_0223c078(3, 0, 0x15, 8);
    SetMainLoopCallback(System_InstallCallbackWhenContextReady);
}

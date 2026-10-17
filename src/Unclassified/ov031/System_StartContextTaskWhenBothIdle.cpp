#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int);
extern "C" void System_InitializeContextTaskAndSleep(void);
extern "C" void func_ov031_02223568(int);
extern "C" void SetMainLoopCallback(void (*)(void));
extern "C" void func_ov031_02231d48(void);
// Original: arm9/ov031 @ 0x02231D08; symbol: func_ov031_02231d08; size: 0x40.
extern "C" void System_StartContextTaskWhenBothIdle(void) {
    if (ReadSelectedContextByte9(1) != 0) return;
    if (ReadSelectedContextByte9(0) != 0) return;
    System_InitializeContextTaskAndSleep();
    func_ov031_02223568(1);
    SetMainLoopCallback(func_ov031_02231d48);
}

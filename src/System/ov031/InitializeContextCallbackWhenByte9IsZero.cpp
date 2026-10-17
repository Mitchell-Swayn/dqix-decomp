#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void func_ov031_02223568(unsigned int value);
extern "C" void func_ov031_02231674(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231648; symbol: func_ov031_02231648; size: 0x2C.
extern "C" void InitializeContextCallbackWhenByte9IsZero(void) {
    if (ReadSelectedContextByte9(0) != 0) return;
    func_ov031_02223568(1);
    SetMainLoopCallback(func_ov031_02231674);
}

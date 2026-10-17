#include <globaldefs.h>
ARM
extern "C" unsigned int ReadSelectedContextByte9(int screen);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02233c74(void);
// Original: arm9/ov031 @ 0x02233C40; symbol: func_ov031_02233c40; size: 0x34.
extern "C" void func_ov031_02233c40(void) {
    if (ReadSelectedContextByte9(1) == 0 && ReadSelectedContextByte9(0) == 0) {
        SetMainLoopCallback(func_ov031_02233c74);
    }
}

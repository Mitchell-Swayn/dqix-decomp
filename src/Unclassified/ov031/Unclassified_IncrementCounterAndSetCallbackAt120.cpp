#include <globaldefs.h>
ARM
extern unsigned char data_ov031_02290c70;
typedef void (*MainLoopCallback)(void);
extern "C" void SetMainLoopCallback(MainLoopCallback callback);
extern "C" void func_ov031_0222a288(void);
// Original: arm9/ov031 @ 0x0222A328; symbol: func_ov031_0222a328; size: 0x34.
extern "C" void Unclassified_IncrementCounterAndSetCallbackAt120(void) {
    unsigned char value = ++data_ov031_02290c70;
    if (value >= 0x78) SetMainLoopCallback(func_ov031_0222a288);
}

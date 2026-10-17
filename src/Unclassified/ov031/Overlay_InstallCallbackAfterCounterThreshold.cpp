#include <globaldefs.h>
ARM
extern "C" {
typedef void (*MainLoopCallback)(void);
void SetMainLoopCallback(MainLoopCallback);
extern unsigned char data_ov031_02290cdc;
void func_ov031_02234440(void);
// Original: arm9/ov031 @ 0x022344EC; symbol: func_ov031_022344ec; size: 0x34.
void Overlay_InstallCallbackAfterCounterThreshold(void) {
    unsigned int next = (unsigned int)data_ov031_02290cdc + 1;
    data_ov031_02290cdc = next;
    unsigned int count = next & 0xff;
    if (count >= 0x78) SetMainLoopCallback(func_ov031_02234440);
}
}

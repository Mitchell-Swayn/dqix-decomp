#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02290cb4;
extern "C" void ConfigureThirdContextEffects(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231B5C; symbol: func_ov031_02231b5c; size: 0x34.
extern "C" void System_IncrementMainLoopCallbackCounter(void) {
    unsigned int count = data_ov031_02290cb4;
    unsigned int next = count + 1;
    unsigned int wrapped = next & 0xFF;
    data_ov031_02290cb4 = next;
    if (wrapped >= 0x78) SetMainLoopCallback(ConfigureThirdContextEffects);
}

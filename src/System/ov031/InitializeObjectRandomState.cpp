#include <globaldefs.h>
ARM
extern "C" unsigned long long func_ov031_02212d20(void);
extern "C" void func_ov031_02211678(void *state, unsigned int seedLow, unsigned int seedHigh);
extern "C" void SetObjectFlagBitZero(unsigned int *object);
// Original: arm9/ov031 @ 0x022115D8; symbol: func_ov031_022115d8; size: 0x30.
extern "C" void InitializeObjectRandomState(void *object, unsigned int value) {
    unsigned long long seed = func_ov031_02212d20();
    func_ov031_02211678((unsigned char *)object + 0x10, (unsigned int)seed, (unsigned int)(seed >> 32));
    *(unsigned int *)((unsigned char *)object + 0x1c) = value;
    SetObjectFlagBitZero((unsigned int *)object);
}

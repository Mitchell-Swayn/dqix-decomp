#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov031_0224e234[];

// Original: arm9/ov031 @ 0x02207620; symbol: func_ov031_02207620; size: 0x2C.
extern "C" void Unclassified_DispatchPointerThroughGlobalCallback(void *value) {
    if (value == 0)
        return;
    unsigned int precedingValue = *(unsigned int *)((unsigned char *)value - 4);
    void (*callback)(int, void *, unsigned int) = (void (*)(int, void *, unsigned int))data_ov031_0224e234[1];
    callback(0, (unsigned char *)value - 4, precedingValue);
}

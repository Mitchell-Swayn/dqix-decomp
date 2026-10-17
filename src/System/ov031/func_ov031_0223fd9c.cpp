#include <globaldefs.h>
ARM
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void *, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *);
extern "C" unsigned char data_ov031_02290fe0[];
extern "C" void System_RunDeferredCallback(void);
extern "C" unsigned char data_ov031_022918a0[];
// Original: arm9/ov031 @ 0x0223FD9C; symbol: func_ov031_0223fd9c; size: 0x48.
extern "C" void func_ov031_0223fd9c(unsigned value) {
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(data_ov031_02290fe0, (unsigned)System_RunDeferredCallback, value, (unsigned)data_ov031_022918a0, 0x800, 0x10);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(data_ov031_02290fe0);
}

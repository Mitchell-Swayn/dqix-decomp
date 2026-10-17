#include <globaldefs.h>
ARM
extern "C" char *data_ov031_0224e580;
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void *context);
// Original: arm9/ov031 @ 0x0220F4A0; symbol: func_ov031_0220f4a0; size: 0x1C.
extern "C" void System_SwitchGlobalProcessorContext(void) {
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(data_ov031_0224e580 + 0x34);
}

#include <globaldefs.h>
ARM
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void* data_ov031_0224e588;
// Original: arm9/ov031 @ 0x022101C4; symbol: func_ov031_022101c4; size: 0x1C.
extern "C" void System_MarkGlobalContextReadyAndSwitch(void) { _Z25MarkContextReadyAndSwitchP16ProcessorContext((char*)data_ov031_0224e588 + 0xa10); }

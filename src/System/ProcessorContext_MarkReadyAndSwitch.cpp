#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct ProcessorContext;extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(ProcessorContext*);
// Original: arm9/main @ 0x020D9828; symbol: func_020d9828; size: 0xC.
extern "C" void ProcessorContext_MarkReadyAndSwitch(ProcessorContext* context){_Z25MarkContextReadyAndSwitchP16ProcessorContext(context);}

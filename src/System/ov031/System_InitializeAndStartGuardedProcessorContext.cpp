#include <globaldefs.h>
ARM
struct ProcessorContext;
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);
extern "C" bool _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" void func_ov031_02216ca0(void*);
extern "C" char * volatile data_ov031_0224e5e8[];
extern "C" char data_ov031_0224e5f0[];
// Original: arm9/ov031 @ 0x022168EC; symbol: func_ov031_022168ec; size: 0xB4.
extern "C" void System_InitializeAndStartGuardedProcessorContext() {
    _Z19ZeroInitializeMutexP5Mutex(data_ov031_0224e5e8[2] + 0x13d8);
    *(unsigned*)(data_ov031_0224e5e8[2] + 0x13f0) = 0;
    char *context = data_ov031_0224e5e8[2];
    if (*(int*)(context + 0x1384)) {
        if (!_Z17IsContextInactiveP16ProcessorContext(context + 0x1318)) return;
    }
    char *base = data_ov031_0224e5e8[2];
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(base + 0x1318,(unsigned)func_ov031_02216ca0,(unsigned)data_ov031_0224e5f0,(unsigned)(base + 0x1000),0x1000,16);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(data_ov031_0224e5e8[2] + 0x1318);
}

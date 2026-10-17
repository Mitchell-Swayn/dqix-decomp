#include <globaldefs.h>
ARM
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);
extern "C" bool _Z17IsContextInactiveP16ProcessorContext(void*);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned data_ov031_0224e608;
extern "C" void func_ov031_02218098(void*);
// Original: arm9/ov031 @ 0x02217DB4; symbol: func_ov031_02217db4; size: 0xBC.
extern "C" void System_InitializeDualMutexWorkerContext(char *self, unsigned priority) {
    *(unsigned*)(self + 0x1c10) = 0;
    _Z19ZeroInitializeMutexP5Mutex(self + 0x1bf8);
    _Z19ZeroInitializeMutexP5Mutex(self + 0x1a18);
    if (*(unsigned*)(self + 0x1018) == 1) data_ov031_0224e608 = 1;
    else data_ov031_0224e608 = 0;
    if (*(unsigned*)(self + 0x1ba4)) {
        if (!_Z17IsContextInactiveP16ProcessorContext(self + 0x1b38)) return;
    }
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj(self + 0x1b38,(unsigned)func_ov031_02218098,(unsigned)self,(unsigned)(self + 0x1000),0x1000,priority);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext(self + 0x1b38);
}

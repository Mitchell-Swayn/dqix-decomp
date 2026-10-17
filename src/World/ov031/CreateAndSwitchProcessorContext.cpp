#include <globaldefs.h>
ARM
extern "C" int Math_SumAlignedHeaderFields(void*);
extern "C" void func_ov031_022052b4();
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int*, int, int);
extern "C" void _Z19ZeroInitializeMutexP5Mutex(void*);
extern "C" void _Z24PopulateProcessorContextP16ProcessorContextjjjjj(void*, unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void _Z25MarkContextReadyAndSwitchP16ProcessorContext(void*);
// Original: arm9/ov031 @ 0x02205648; symbol: func_ov031_02205648; size: 0x74.
extern "C" unsigned CreateAndSwitchProcessorContext(unsigned entry, int* queue, unsigned char* parameters) {
    unsigned offset = Math_SumAlignedHeaderFields(parameters);
    InitializeEightWordQueueStateWithTwoParameters(queue, entry, parameters[3]);
    _Z19ZeroInitializeMutexP5Mutex((char*)queue + 0xe0);
    _Z24PopulateProcessorContextP16ProcessorContextjjjjj((char*)queue + 0x20, (unsigned)func_ov031_022052b4, (unsigned)queue, entry + offset, *(unsigned short*)parameters, parameters[2]);
    _Z25MarkContextReadyAndSwitchP16ProcessorContext((char*)queue + 0x20);
    return entry + offset;
}

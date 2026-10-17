#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
extern "C" unsigned int data_ov031_02249680;
extern "C" unsigned char data_ov031_0224cbe8;
extern "C" unsigned char data_ov031_0224cb28;

// Original: arm9/ov031 @ 0x0220057C; symbol: func_ov031_0220057c; size: 0x38.
extern "C" void System_SetProcessorContextPriorities(unsigned int priority) {
    data_ov031_02249680 = priority;
    ChangeContextPriority((ProcessorContext *)&data_ov031_0224cbe8, priority);
    ChangeContextPriority((ProcessorContext *)&data_ov031_0224cb28, priority);
}

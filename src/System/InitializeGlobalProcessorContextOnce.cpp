#include <globaldefs.h>
#include "System/ProcessorContext.h"
#include "System/Interrupts.h"
extern "C" ProcessorContext* data_02112328;extern "C" char data_0211232c[];extern "C" char data_02112750[];extern "C" void SystemWorker_RunPendingMessagesUntilStopped();extern "C" void ClearThirtySixByteMemoryRange(void*);
// Original: arm9/main @ 0x020D1954; symbol: func_020d1954; size: 0x8C.
extern "C" ARM void InitializeGlobalProcessorContextOnce(ProcessorContext* p){int irq=DisableIRQInterrupts();if(!data_02112328){data_02112328=p;ClearThirtySixByteMemoryRange((char*)p+0xc4);ClearThirtySixByteMemoryRange(data_0211232c);*(unsigned*)((char*)p+0xc0)=0;PopulateProcessorContext(p,(unsigned)SystemWorker_RunPendingMessagesUntilStopped,(unsigned)p,(unsigned)data_02112750,0x400,20);MarkContextReadyAndSwitch(p);}SetIRQInterruptState(irq);}

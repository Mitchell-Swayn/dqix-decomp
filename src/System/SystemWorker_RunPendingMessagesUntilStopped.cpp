#include <globaldefs.h>
#include <System/Memory.h>
#include <System/Interrupts.h>
#include <System/ProcessorContext.h>
#pragma always_inline on
#pragma optimization_level 4
#pragma optimize_for_size off
union Message {struct Fields {unsigned (*execute)(Message*);void(*complete)(Message*);unsigned result;unsigned payload[6];} fields;unsigned words[9];};struct Worker{char pad[192];Message* volatile pending;};struct Control{unsigned active;char pad[34];unsigned char busy;};extern Control data_02112328;
// Original: arm9/main @ 0x020D19F4; symbol: func_020d19f4; size: 0xF0.
extern "C" void SystemWorker_RunPendingMessagesUntilStopped(Worker* worker){Message message;for(;;){VectorizedMemset(&message,0,36);int irq=DisableIRQInterrupts();while(!worker->pending)BlockCurrentContext(0);message=*worker->pending;SetIRQInterruptState(irq);if(message.fields.execute)message.fields.result=message.fields.execute(&message);irq=DisableIRQInterrupts();void(*complete)(Message*)=message.fields.complete;data_02112328.busy=0;if(complete)complete(&message);if(!data_02112328.active)break;worker->pending=0;SetIRQInterruptState(irq);}ContextExecutionReturnProc();}

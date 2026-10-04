/* Initialize subsystem receivers and start the sixteen-entry SPI task worker. */
#pragma dont_inline on
#include "SpiService.h"
/* The startup WRAM clear initializes the complete service allocation. */
SpiServiceState ARM7_SpiServiceState;
extern void ARM7_InitializeTouchState(void);
extern void ARM7_InitializeSpiExternalState(void);
extern void ARM7_InitializeMicrophoneState(void);
extern void ARM7_InitializePowerState(void);
extern void ARM7_StartIPC(void);
extern void ARM7_SetIpcHandler(int,void(*)(int,unsigned int,int));
extern void ARM7_SpiIpcCallback(int,unsigned int,int);
extern void ARM7_InitializeMessageQueue(MessageQueue*,void**,int);
extern void ARM7_FillBytes(void*,unsigned int,unsigned int);
extern void ARM7_CreateThread(ProcessorContext*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
extern void ARM7_MarkThreadReady(ProcessorContext*);
extern void ARM7_SpiWorkerMain(void);
void ARM7_InitializeSpiServices(unsigned int priority)
{
 int i;
 if(ARM7_SpiServiceState.initialized)return;
 ARM7_SpiServiceState.initialized=1;
 ARM7_SpiServiceState.body.busy=0;
 ARM7_SpiServiceState.body.owner=5;
 ARM7_InitializeTouchState();
 ARM7_InitializeSpiExternalState();
 ARM7_InitializeMicrophoneState();
 ARM7_InitializePowerState();
 ARM7_StartIPC();
 ARM7_SetIpcHandler(6,ARM7_SpiIpcCallback);
 ARM7_SetIpcHandler(9,ARM7_SpiIpcCallback);
 ARM7_SetIpcHandler(8,ARM7_SpiIpcCallback);
 ARM7_SetIpcHandler(4,ARM7_SpiIpcCallback);
 ARM7_InitializeMessageQueue(&ARM7_SpiTaskQueue,ARM7_SpiServiceState.body.messages,16);
 i=0;
 do {
  ARM7_FillBytes(&ARM7_SpiServiceState.body.tasks[i],0,sizeof(SpiTask));
  i++;
 } while(i<16);
 ARM7_SpiServiceState.body.nextTask=0;
 ARM7_SpiServiceState.body.waiters.last=0;
 ARM7_SpiServiceState.body.waiters.first=0;
 ARM7_CreateThread(&ARM7_SpiServiceState.body.thread,(unsigned int)ARM7_SpiWorkerMain,0,
  (unsigned int)&ARM7_SpiTaskQueue,0x200,priority);
 ARM7_MarkThreadReady(&ARM7_SpiServiceState.body.thread);
}

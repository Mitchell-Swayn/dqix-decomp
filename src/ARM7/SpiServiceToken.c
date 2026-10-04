/* Blocking SPI ownership for the cookie-identified external service client. */
#pragma dont_inline on
#include "SpiService.h"
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern void ARM7_BlockCurrentThread(BlockedContextList*);
extern void ARM7_UnblockThreads(BlockedContextList*);
void ARM7_AcquireSpiServiceToken(unsigned int cookie)
{
 int state;
 for(;;) {
  state=ARM7_DisableIRQInterrupts();
  if(!ARM7_SpiServiceState.body.busy)break;
  ARM7_SetIRQInterruptState(state);
  ARM7_BlockCurrentThread(&ARM7_SpiServiceWaiters);
 }
 ARM7_SpiServiceState.body.busy=1;
 ARM7_SpiServiceState.body.owner=4;
 ARM7_SpiServiceState.body.cookie=cookie;
 ARM7_SetIRQInterruptState(state);
}
void ARM7_ReleaseSpiServiceToken(unsigned int cookie)
{
 if(ARM7_SpiServiceState.body.busy &&
    ARM7_SpiServiceState.body.owner==4 &&
    ARM7_SpiServiceState.body.cookie==cookie) {
  int state=ARM7_DisableIRQInterrupts();
  ARM7_SpiServiceState.body.owner=5;
  ARM7_SpiServiceState.body.busy=0;
  ARM7_SpiServiceState.body.cookie=0;
  ARM7_SetIRQInterruptState(state);
  ARM7_UnblockThreads(&ARM7_SpiServiceWaiters);
 }
}

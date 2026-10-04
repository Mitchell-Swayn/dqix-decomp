/* Shared SPI ownership checks and owner-matched release/wakeup. */
#pragma dont_inline on
#include "SpiService.h"
extern void ARM7_UnblockThreads(BlockedContextList*);
int ARM7_IsSpiServiceAvailable(int unused)
{
 return ARM7_SpiServiceState.body.busy==0;
}
void ARM7_AcquireSpiService(int owner)
{
 ARM7_SpiServiceState.body.busy=1;
 ARM7_SpiServiceState.body.owner=owner;
}
void ARM7_ReleaseSpiService(int owner)
{
 if(ARM7_SpiServiceState.body.owner==owner) {
  ARM7_SpiServiceState.body.owner=5;
  ARM7_SpiServiceState.body.busy=0;
  ARM7_UnblockThreads(&ARM7_SpiServiceWaiters);
 }
}

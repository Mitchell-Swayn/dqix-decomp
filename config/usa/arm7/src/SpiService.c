/* Shared SPI ownership checks and owner-matched release/wakeup. */
#pragma dont_inline on
#include "SpiService.h"
extern void ARM7_UnblockThreads(BlockedContextList*);
// Original: arm7/wram @ 0x03804D20; symbol: ARM7_IsSpiServiceAvailable.
int ARM7_IsSpiServiceAvailable(int unused)
{
 return ARM7_SpiServiceState.body.busy==0;
}
// Original: arm7/wram @ 0x03804D3C; symbol: ARM7_AcquireSpiService.
void ARM7_AcquireSpiService(int owner)
{
 ARM7_SpiServiceState.body.busy=1;
 ARM7_SpiServiceState.body.owner=owner;
}
// Original: arm7/wram @ 0x03804D54; symbol: ARM7_ReleaseSpiService.
void ARM7_ReleaseSpiService(int owner)
{
 if(ARM7_SpiServiceState.body.owner==owner) {
  ARM7_SpiServiceState.body.owner=5;
  ARM7_SpiServiceState.body.busy=0;
  ARM7_UnblockThreads(&ARM7_SpiServiceWaiters);
 }
}

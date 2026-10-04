/* Latch card removal using a locked identity check or the hardware IRQ flag. */
#pragma dont_inline on
#include "CardRemoval.h"
extern int ARM7_CheckCardIdentity(void);
extern int ARM7_CheckCardInterrupt(void);
extern int ARM7_AllocateLockOwner(void);
extern void ARM7_ReleaseLockOwner(unsigned short);
extern int ARM7_TryAcquireNDSBus(unsigned short);
extern int ARM7_ReleaseNDSBus(unsigned short);
extern unsigned int ARM7_ReadCardIdLocked(void);
unsigned int ARM7_IsCardRemoved(void)
{
 if(!ARM7_CardRemovalState.removed) {
  if(*(volatile unsigned char*)0x027ffe1f&0x80)ARM7_CheckCardIdentity();
  else ARM7_CheckCardInterrupt();
 }
 return ARM7_CardRemovalState.removed;
}
int ARM7_CheckCardIdentity(void)
{
 int present=1;
 int owner=ARM7_AllocateLockOwner();
 if(owner!=-3) {
  if(ARM7_TryAcquireNDSBus((unsigned short)owner)==0) {
   volatile unsigned int expected;
   unsigned int actual;
   expected=*(volatile unsigned int*)(*(volatile unsigned short*)0x027ffc10==0?0x027ff800:0x027ffc00);
   actual=ARM7_ReadCardIdLocked();
   present=actual==expected;
   ARM7_ReleaseNDSBus((unsigned short)owner);
  }
  ARM7_ReleaseLockOwner((unsigned short)owner);
 }
 ARM7_CardRemovalState.removed=!present;
 return present;
}
#pragma dont_inline off
static inline unsigned int ReadPendingInterrupts(void) {return *(volatile unsigned int*)0x04000214;}
int ARM7_CheckCardInterrupt(void)
{
 unsigned int pending=ReadPendingInterrupts();
 int present=1;
 if(pending&0x100000) {
  present=0;
  ARM7_CardRemovalState.removed=1;
 }
 return present;
}

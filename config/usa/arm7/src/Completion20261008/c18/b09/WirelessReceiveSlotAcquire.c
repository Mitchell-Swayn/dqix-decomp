#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E0700; symbol: ARM7_WirelessReceiveSlotAcquire.
WirelessReceiveSlot *ARM7_WirelessReceiveSlotAcquire(void) {
 WirelessReceiveSlot *slot=0; int index; int previous;
 previous=ARM7_DisableInterrupts();
 if(ARM7_WirelessState.receive) {
  for(index=0;index<32;index++) {
   if(ARM7_WirelessState.receive->slots[index].flags&0x8000) {
    slot=&ARM7_WirelessState.receive->slots[index];
    slot->flags &= ~0x8000; break;
   }
  }
 }
 ARM7_RestoreInterrupts(previous);return slot;
}

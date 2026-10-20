#include <globaldefs.h>
ARM
struct Owner;
extern "C" void Util_AddCountToGroupedHalfwordEntry(Owner*,unsigned,int,int);
struct PendingSlots {char pad[0x72];unsigned short groups[3];short ids[3];};
// Original: arm9/ov006 @ 0x02159094; symbol: func_ov006_02159094; size: 0x74.
// Restores the last positive pending grouped entry and clears its group, ID and count.
extern "C" void RestoreLastPendingGroupedEntry(unsigned char* self) {
 for(signed char i=2;i>=0;--i) {
  int id=((PendingSlots*)(self+0x300))->ids[i];
  if(id>0) {
   unsigned char* counts=self+0x38c;
   Util_AddCountToGroupedHalfwordEntry((Owner*)self,(unsigned char)((PendingSlots*)(self+0x300))->groups[i],id,counts[i]);
   ((PendingSlots*)(self+0x300))->groups[i]=0;
   ((PendingSlots*)(self+0x300))->ids[i]=-1;
   counts[i]=0;return;
  }
 }
}

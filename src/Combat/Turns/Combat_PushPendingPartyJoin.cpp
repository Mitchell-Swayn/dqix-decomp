#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x0215FAB0; symbol: RecordByteIfCapacityAvailable; behavior follows recorded disassembly.
extern "C" void Combat_PushPendingPartyJoin(unsigned char *base, unsigned char value) {  if(base[0x8e47]>=3)return; unsigned char i=base[0x8e47]++; *(base+0x8e44+i)=value; }

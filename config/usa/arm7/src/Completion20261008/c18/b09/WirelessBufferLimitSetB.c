#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E07F0; symbol: ARM7_WirelessBufferLimitSetB.
void ARM7_WirelessBufferLimitSetB(unsigned short limit) {
 volatile WirelessBufferControl *buffer=ARM7_WirelessState.buffer;
 if(limit>512)limit=512;
 buffer->shadowB=limit;buffer->limitB=limit;
 if(buffer->bank==0) {unsigned short end=limit+2;buffer->shadowEndB=end;buffer->endB=end;}
 else {unsigned short end=limit+2;buffer->shadowEndA=end;buffer->endA=end;}
}

#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E07A0; symbol: ARM7_WirelessBufferLimitSetA.
void ARM7_WirelessBufferLimitSetA(unsigned short limit) {
 volatile WirelessBufferControl *buffer=ARM7_WirelessState.buffer;
 if(limit>512)limit=512;
 buffer->limitA=limit;buffer->shadowA=limit;
 if(buffer->bank==0) {unsigned short end=limit+4;buffer->shadowEndA=end;buffer->endA=end;}
 else {unsigned short end=limit+4;buffer->shadowEndB=end;buffer->endB=end;}
}

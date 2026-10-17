#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E086C; symbol: ARM7_WirelessBufferPositionSetB.
void ARM7_WirelessBufferPositionSetB(unsigned int position) {
 volatile WirelessBufferControl *buffer=ARM7_WirelessState.buffer;
 buffer->limitB=position;
 if(buffer->bank==0)buffer->endB=position+2;
 else buffer->endA=position+2;
}

#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E0840; symbol: ARM7_WirelessBufferPositionSetA.
void ARM7_WirelessBufferPositionSetA(unsigned int position) {
 volatile WirelessBufferControl *buffer=ARM7_WirelessState.buffer;
 buffer->limitA=position;
 if(buffer->bank==0)buffer->endA=position+4;
 else buffer->endB=position+4;
}

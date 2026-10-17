#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E076C; symbol: ARM7_WirelessBufferLimitsClear.
void ARM7_WirelessBufferLimitsClear(void) {
 volatile WirelessBufferControl *buffer=ARM7_WirelessState.buffer;
 buffer->endA=0;buffer->endB=0;buffer->limitA=0;buffer->limitB=0;
 buffer->shadowEndA=0;buffer->shadowEndB=0;buffer->shadowA=0;buffer->shadowB=0;
}

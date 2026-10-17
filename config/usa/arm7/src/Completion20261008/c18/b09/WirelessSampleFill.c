#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E0564; symbol: ARM7_WirelessSampleFill.
void ARM7_WirelessSampleFill(unsigned char sample) {
 int index=0;
 do {((WirelessRootView*)((unsigned char*)&ARM7_WirelessRoot+index))->state.samples[0]=sample;index++;}while(index<32);
 ARM7_WirelessState.sampleIndex=0;
}

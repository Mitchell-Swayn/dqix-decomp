#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E059C; symbol: ARM7_WirelessSampleAverage.
unsigned int ARM7_WirelessSampleAverage(void) {
 int index;unsigned int sum=0;index=sum;
 do {sum+=((WirelessRootView*)((unsigned char*)&ARM7_WirelessRoot+index))->state.samples[0];index++;}while(index<32);
 return ARM7_WirelessSignalClassify(sum>>5);
}

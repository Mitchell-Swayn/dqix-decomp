#pragma dont_inline on
#include "WirelessHelpers.h"
// Original: arm7/mainram @ 0x027E05D8; symbol: ARM7_WirelessSignalClassify.
unsigned int ARM7_WirelessSignalClassify(unsigned int sample) {
 if(ARM7_WirelessState.receive->signalMode==8) {
  if(sample<22)return 0; if(sample<28)return 1;
  return sample<34?2:3;
 }
 if(sample<8)return 0; if(sample<14)return 1;
 return sample<20?2:3;
}

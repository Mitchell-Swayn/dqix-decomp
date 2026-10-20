#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void Network_BeginChannelLoadMeasurement();
// Original: arm9/main @ 0x0202B7EC; symbol: func_0202b7ec; size: 0x14.
extern "C" void Network_BeginHostingSession(unsigned* p){*p=2;Network_BeginChannelLoadMeasurement();}

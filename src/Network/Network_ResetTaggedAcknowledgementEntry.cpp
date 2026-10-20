#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020E3840; symbol: func_020e3840; size: 0x1C.
extern "C" void Network_ResetTaggedAcknowledgementEntry(unsigned char* p) { *(unsigned int*)p=0xffffffff;p[4]=0;p[5]=0;p[6]=0; }

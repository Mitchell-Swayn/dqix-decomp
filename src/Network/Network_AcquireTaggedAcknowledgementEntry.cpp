#include <globaldefs.h>
ARM
extern "C" void Network_ResetTaggedAcknowledgementEntry(void*);
// Original: arm9/main @ 0x020E38A0; symbol: func_020e38a0; size: 0x44.
extern "C" void* Network_AcquireTaggedAcknowledgementEntry(unsigned char* p){for(int i=0;i<4;++i,p+=8){if(!p[4]){Network_ResetTaggedAcknowledgementEntry(p);return p;}}return 0;}

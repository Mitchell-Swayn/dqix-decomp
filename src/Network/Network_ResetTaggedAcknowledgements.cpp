#include <globaldefs.h>
extern "C" {
void Network_ResetTaggedAcknowledgementEntry(void *);
// Original: arm9/main @ 0x020E3814; symbol: func_020e3814; size: 0x2C.
void Network_ResetTaggedAcknowledgements(char *p){for(int i=0;i<4;i++,p+=8)Network_ResetTaggedAcknowledgementEntry(p);}
}

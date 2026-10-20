#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
unsigned char *Network_FindTaggedAcknowledgement(void *,int);
// Original: arm9/main @ 0x020E3AD0; symbol: func_020e3ad0; size: 0x38.
bool Network_IsTaggedAcknowledgementCompleteOrAbsent(void *p,int i){unsigned char *q=Network_FindTaggedAcknowledgement(p,i);if(!q)return true;if(q[5]&&q[5]==q[6])return true;return false;}
}

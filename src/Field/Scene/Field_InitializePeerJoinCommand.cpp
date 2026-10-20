#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
// Original: arm9/ov017 @ 0x021AEEDC; symbol: func_ov017_021aeedc; size: 0x30.
// Initializes a type-0x25 record and its byte/halfword state fields.
extern "C" void Field_InitializePeerJoinCommand(signed char *p) {
 LinkedQueue_InitializeNodeStatus(p);
 p[0]=0x25; p[8]=0; p[15]=-1; *(unsigned short *)(p+18)=0; p[16]=-1;
}

#include <globaldefs.h>
// Original: arm9/main @ 0x0204BEF4; symbol: func_0204bef4; size: 0x3C.
extern "C" int ActorDescriptor_DecodeMenuDecimalIdentifier(const unsigned short* p) { unsigned v=*p; return (short)(v&31)*100+20000+(unsigned short)((v&0x3e0)>>5)*10+(unsigned short)((v&0x7c00)>>10); }

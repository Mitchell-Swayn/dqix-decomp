#include <globaldefs.h>
ARM
extern "C" void ClearFourBytes_Main020E303C(void*);
// Original: arm9/main @ 0x020E3544; symbol: func_020e3544; size: 0x3C.
extern "C" void ProcessAllEightRecordsMatchingByteType(unsigned char* p,unsigned type){for(int i=0;i<8;++i,p+=4){if(*p==type)ClearFourBytes_Main020E303C(p);}}

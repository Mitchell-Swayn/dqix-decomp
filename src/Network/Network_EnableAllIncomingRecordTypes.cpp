#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void* memset(void*,int,unsigned);
// Original: arm9/main @ 0x0205E854; symbol: func_0205e854; size: 0x1C.
extern "C" void* Network_EnableAllIncomingRecordTypes(unsigned char* p){return memset(p+0x1524,255,32);}

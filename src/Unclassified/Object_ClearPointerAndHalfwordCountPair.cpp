#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0207F510; symbol: func_0207f510; size: 0x14.
extern "C" void Object_ClearPointerAndHalfwordCountPair(unsigned char* p) { *(unsigned int*)p=0; *(unsigned short*)(p+6)=0; *(unsigned short*)(p+4)=0; }

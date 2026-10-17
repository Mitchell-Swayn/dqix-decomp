#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208978C; symbol: func_0208978c; size: 0x10.
extern "C" void Object_SetHalfword32AndSavePreviousIn34(unsigned char* p, short v) { *(short*)(p+0x34)=*(short*)(p+0x32); *(short*)(p+0x32)=v; }

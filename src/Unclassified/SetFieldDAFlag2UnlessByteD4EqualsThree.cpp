#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0208BEB4; symbol: func_0208beb4; size: 0x18.
extern "C" void SetFieldDAFlag2UnlessByteD4EqualsThree(unsigned char* p) { if (p[0xd4]!=3) *(unsigned short*)(p+0xda)|=2; }

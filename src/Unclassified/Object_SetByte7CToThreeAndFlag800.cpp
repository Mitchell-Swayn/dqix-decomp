#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02089174; symbol: func_02089174; size: 0x20.
extern "C" void Object_SetByte7CToThreeAndFlag800(unsigned char* p) { p[0x7c]=3;p[0x9f]=0;*(unsigned int*)(p+0x18)|=0x800; }

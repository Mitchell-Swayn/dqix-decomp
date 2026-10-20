#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/main @ 0x0204F0EC; symbol: func_0204f0ec; size: 0x4C.
extern "C" void TextCanvas_ClearMarkedTextRectangles(unsigned char* p) { memset(p+12,0,36);memset(p+48,0,36);memset(p+84,0,36);memset(p+120,0,36); }

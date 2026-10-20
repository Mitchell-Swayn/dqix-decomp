#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02054234; symbol: func_02054234; size: 0x14.
extern "C" void GameObject_RequestTransitionFlagDisable(unsigned char* p) { unsigned int* v=(unsigned int*)(p+0x18c); *v=(*v & ~0x80) | 0x100; }

#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void GameObject_CopyContactDescriptor(void*,const void*);
// Original: arm9/main @ 0x02033FA8; symbol: func_02033fa8; size: 0x1C.
extern "C" void GameObject_SetWallContactDescriptor(unsigned char* p,const void* source){p[224]|=128;GameObject_CopyContactDescriptor(p+284,source);}

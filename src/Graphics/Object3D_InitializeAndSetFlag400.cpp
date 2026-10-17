#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D10InitializeEv(void*);
// Original: arm9/main @ 0x020484D0; symbol: func_020484d0; size: 0x28.
 extern "C" void Object3D_InitializeAndSetFlag400(unsigned char* p) { _ZN8Object3D10InitializeEv(p); *(unsigned short*)p|=0x400;*(unsigned int*)(p+0xb0)=0;*(unsigned int*)(p+0xac)=0; }

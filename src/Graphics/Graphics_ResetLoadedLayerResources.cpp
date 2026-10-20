#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetCharacterResourceHeader(void*);extern "C" void Tilemap_ResetResourceDescriptor(void*);
// Original: arm9/main @ 0x0204AFB4; symbol: func_0204afb4; size: 0x5C.
extern "C" void Graphics_ResetLoadedLayerResources(unsigned char* p){*(int*)(p+20)=0;Graphics_ResetCharacterResourceHeader(p);p[12]=0;*(unsigned short*)(p+14)=65535;if(!*(void**)(p+16))return;for(unsigned char i=0;i<p[29];++i)Tilemap_ResetResourceDescriptor(*(unsigned char**)(p+16)+i*16);}

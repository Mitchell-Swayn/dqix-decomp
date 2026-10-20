#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203F354; symbol: func_0203f354; size: 0x1C.
extern "C" unsigned char* ActorSpriteResource_GetFrame(unsigned char* p,unsigned int i) { if (*(unsigned short*)(p+6)<=i) return 0; return *(unsigned char**)(p+8)+i*20; }

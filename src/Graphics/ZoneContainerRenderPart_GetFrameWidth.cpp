#include <globaldefs.h>
ARM
struct Record { unsigned char padding[0x84]; unsigned char active:1; unsigned char rest:7; };
// Original: arm9/main @ 0x02047A5C; symbol: func_02047a5c; size: 0x1C.
 extern "C" unsigned int ZoneContainerRenderPart_GetFrameWidth(Record* p,unsigned int i) { if (p->active) return (*(unsigned char**)((unsigned char*)p+8))[i*8]; return 0; }

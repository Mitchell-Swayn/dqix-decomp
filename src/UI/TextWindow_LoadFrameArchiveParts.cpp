#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void LoadEightNamedArchiveRenderParts(void*,int);
// Original: arm9/main @ 0x020440B8; symbol: func_020440b8; size: 0x14.
extern "C" void TextWindow_LoadFrameArchiveParts(unsigned char* p,int mode){LoadEightNamedArchiveRenderParts(p+0x19e0,mode);}

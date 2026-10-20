#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);extern "C" void Text_EncodeGlyphIndices(unsigned,void*,int);
// Original: arm9/main @ 0x02052A10; symbol: func_02052a10; size: 0x3C.
extern "C" unsigned char* GameObject_EncodeNameAsGlyphIds(unsigned char* object){memset(object+0x141,0,12);Text_EncodeGlyphIndices(*(unsigned*)(object+0x134),object+0x141,1);return object+0x141;}

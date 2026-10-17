#include <globaldefs.h>
struct Stream {const unsigned short* data;unsigned(*read)(const unsigned short**);};
extern "C" unsigned TextStream_ReadAndAdvanceHalfword(const unsigned short**);
extern "C" void Graphics_FindFontInformation(unsigned,Stream*);
// Original: arm9/main @ 0x020B0E48; symbol: func_020b0e48; size: 0x24.
extern "C" void TextStream_InitializeHalfwordReader(Stream* p,unsigned a) {Graphics_FindFontInformation(a,p);p->read=TextStream_ReadAndAdvanceHalfword;}

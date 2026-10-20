#include <globaldefs.h>
ARM
extern "C" char* NNS_G2dFindBinaryBlock(unsigned,unsigned,unsigned,unsigned); extern "C" void NNSi_G2dUnpackNCLCmpInfo(char*);
// Original: arm9/main @ 0x020B022C; symbol: func_020b022c; size: 0x3C.
 extern "C" int NNS_G2dGetUnpackedPaletteCompressInfo(unsigned a,char** out,unsigned c,unsigned d){char* p=NNS_G2dFindBinaryBlock(a,0x50434d50,c,d); if(!p){*out=0;return 0;}NNSi_G2dUnpackNCLCmpInfo(p+8);*out=p+8;return 1;}

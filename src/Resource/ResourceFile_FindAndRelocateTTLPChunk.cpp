#include <globaldefs.h>
extern "C" char* NNS_G2dFindBinaryBlock(unsigned,unsigned,unsigned,unsigned);
extern "C" void NNS_G2dUnpackNCL(char*);
// Original: arm9/main @ 0x020B01F0; symbol: func_020b01f0; size: 0x3C.
extern "C" int ResourceFile_FindAndRelocateTTLPChunk(unsigned a,char** out,unsigned c,unsigned d) {char* p=NNS_G2dFindBinaryBlock(a,0x504c5454,c,d);if(!p){*out=0;return 0;}NNS_G2dUnpackNCL(p+8);*out=p+8;return 1;}

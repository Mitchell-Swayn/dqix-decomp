#include <globaldefs.h>
ARM
extern "C" char* NNS_G2dFindBinaryBlock(void*,unsigned);extern "C" void NNS_G2dUnpackNCG(void*);
// Original: arm9/main @ 0x020B01A4; symbol: func_020b01a4; size: 0x3C.
extern "C" int NNS_G2dGetUnpackedCharacterData(void* file,void** out){char* p=NNS_G2dFindBinaryBlock(file,0x43484152);if(!p){*out=0;return 0;}NNS_G2dUnpackNCG(p+8);*out=p+8;return 1;}

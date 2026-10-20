#include <globaldefs.h>
extern "C" int NNSi_SndArcLoadSeq(unsigned,int,unsigned,int,int);
// Original: arm9/main @ 0x020BDC98; symbol: func_020bdc98; size: 0x2C.
extern "C" ARM bool NNS_SndArcLoadSeq(unsigned a,unsigned b){return NNSi_SndArcLoadSeq(a,255,b,1,0)==0;}

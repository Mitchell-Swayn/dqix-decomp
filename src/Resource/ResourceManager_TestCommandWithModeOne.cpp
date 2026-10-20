#include <globaldefs.h>
extern "C" int NNSi_SndArcLoadSeq(unsigned,unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020BDCC4; symbol: func_020bdcc4; size: 0x24.
extern "C" bool ResourceManager_TestCommandWithModeOne(unsigned a,unsigned b,unsigned c) {return NNSi_SndArcLoadSeq(a,b,c,1,0)==0;}

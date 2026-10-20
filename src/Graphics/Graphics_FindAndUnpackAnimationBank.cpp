#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" char* NNS_G2dFindBinaryBlock(unsigned,unsigned,unsigned,unsigned);
extern "C" void NNS_G2dUnpackNAN(char*);
// Original: arm9/main @ 0x020AFEC4; symbol: func_020afec4; size: 0x3C.
extern "C" int Graphics_FindAndUnpackAnimationBank(unsigned a,char** out,unsigned c,unsigned d){
    char* p=NNS_G2dFindBinaryBlock(a,0x41424e4b,c,d);
    if(!p){*out=0;return 0;}
    NNS_G2dUnpackNAN(p+8);
    *out=p+8;
    return 1;
}

#include <globaldefs.h>
extern "C" void WriteOrApplyHalfwordFileStatePair(void*,int,int,int);struct State{int active;unsigned char pad[0xa8];short first,second;};
// Original: arm9/main @ 0x0203AA08; symbol: func_0203aa08; size: 0x3C.
extern "C" ARM void ConsumeActivePairAndInvalidateIndices(State* p){if(!p->active)return;if(p->first<0)return;WriteOrApplyHalfwordFileStatePair(p,p->first,p->second,0);p->first=-1;p->second=-1;}

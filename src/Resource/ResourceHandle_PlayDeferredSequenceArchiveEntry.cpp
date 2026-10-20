#include <globaldefs.h>
extern "C" void ResourceHandle_StartOrDeferSequenceArchiveEntry(void*,int,int,int);struct State{int active;unsigned char pad[0xa8];short first,second;};
// Original: arm9/main @ 0x0203AA08; symbol: func_0203aa08; size: 0x3C.
extern "C" ARM void ResourceHandle_PlayDeferredSequenceArchiveEntry(State* p){if(!p->active)return;if(p->first<0)return;ResourceHandle_StartOrDeferSequenceArchiveEntry(p,p->first,p->second,0);p->first=-1;p->second=-1;}

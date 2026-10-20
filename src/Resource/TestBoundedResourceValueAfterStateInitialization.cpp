#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" void* ResourceManager_ExchangeGlobalValue(void*);extern "C" int NNS_SndArcLoadGroup(int,void*);struct Context{void* pointer;unsigned state;};
// Original: arm9/main @ 0x0203AA98; symbol: func_0203aa98; size: 0x60.
extern "C" ARM bool TestBoundedResourceValueAfterStateInitialization(Context*p,int value){if(!p->pointer)return false;if(value>=65535 || value<0)return false;ResourceManager_ExchangeGlobalValue(&p->state);return NNS_SndArcLoadGroup(value,p->pointer)!=0;}

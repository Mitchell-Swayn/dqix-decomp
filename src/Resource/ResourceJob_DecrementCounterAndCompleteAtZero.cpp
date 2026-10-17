#include <globaldefs.h>
struct Object {char pad[0x120];unsigned counter;};
extern "C" void ReleasePresentDataAndClearSize(Object*);
// Original: arm9/main @ 0x020BF2D4; symbol: func_020bf2d4; size: 0x24.
extern "C" void ResourceJob_DecrementCounterAndCompleteAtZero(Object* p) {if(!p->counter)return;p->counter--;if(p->counter)return;ReleasePresentDataAndClearSize(p);}

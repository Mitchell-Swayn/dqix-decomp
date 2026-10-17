#include <globaldefs.h>
extern "C" void ResetCounterAndSetFlagBitSix(void*);
struct Object{unsigned short flags;char pad[0x136];unsigned a,b;unsigned char status;};
// Original: arm9/main @ 0x020489BC; symbol: func_020489bc; size: 0x2C.
extern "C" ARM void ResetStateAndSetFlag80(Object* p){ResetCounterAndSetFlagBitSix(p);p->flags|=0x80;p->b=0;p->a=0;p->status=0;}

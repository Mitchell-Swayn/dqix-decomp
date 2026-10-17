#include <globaldefs.h>
ARM
struct Object {char pad[28];unsigned count:10;unsigned rest:22;};
// Original: arm9/main @ 0x020A0258; symbol: func_020a0258; size: 0x3C.
extern "C" void AddToCountClamped1023(Object* p,unsigned add){unsigned n=p->count+add;if(n>1023)n=1023;p->count=n;}

#include <globaldefs.h>
#pragma optimization_level 1
// Original: arm9/main @ 0x02053DD0; symbol: func_02053dd0; size: 0x2C.
ARM void IncrementLinkedWordCounterUnlessResourceFlagSet(char* p){volatile unsigned* v;unsigned* q=*(unsigned**)(p+0x19c);if(!q)return;if(*(unsigned*)(*(char**)(p+0x138)+0x14)&1)return;v=q+2;*v=*v+1;}

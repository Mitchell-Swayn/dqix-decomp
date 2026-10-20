#include <globaldefs.h>
ARM
struct Field {unsigned value:9;unsigned rest:23;};
// Original: arm9/main @ 0x020A0460; symbol: func_020a0460; size: 0x34.
extern "C" void Statistics_AddNewMonsterSpeciesCount(char* p,unsigned n){volatile Field* f=(volatile Field*)(p+20);unsigned v=n+f->value;if(v>500)v=500;f->value=v;}

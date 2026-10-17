#include <globaldefs.h>
ARM
struct Entry{unsigned x,y;unsigned char serial;unsigned char pad[3];};extern "C" Entry data_02114260[];
// Original: arm9/main @ 0x020D2980; symbol: func_020d2980; size: 0x30.
extern "C" unsigned WriteIndexedPairAndIncrementSerial(unsigned index,unsigned x,unsigned y){Entry* p=data_02114260+index;p->x=x;p->y=y;return ++p->serial;}

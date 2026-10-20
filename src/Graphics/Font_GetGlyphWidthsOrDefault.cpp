#include <globaldefs.h>
#pragma optimization_level 4
#pragma optimize_for_size off
struct Range {unsigned short begin,end;Range* next;unsigned char records[3];};struct Set {char pad[12];Range* ranges;};
// Original: arm9/main @ 0x020B0EB4; symbol: func_020b0eb4; size: 0x4C.
extern "C" ARM const unsigned char* Font_GetGlyphWidthsOrDefault(Set** p,unsigned id){Range* range;unsigned begin;Set* set=*p;range=set->ranges;if(range){do{begin=range->begin;if(begin<=id&&id<=range->end)return range->records+(id-begin)*3;range=range->next;}while(range);}return (unsigned char*)set+4;}

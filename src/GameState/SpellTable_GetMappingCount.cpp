// Original ARM fields and widths reviewed.
struct Flags{unsigned int value:12;unsigned int rest:20;};
// Original: arm9/main @ 0x0209AA40; symbol: func_0209aa40; size: 0x14.
extern "C" unsigned int SpellTable_GetMappingCount(char** p){char* q=*p;if(q)return *(unsigned int*)(q+0x108);return 0;}

#include <globaldefs.h>
struct Record{char pad[20];unsigned a:9;unsigned b:9;unsigned c:11;unsigned rest:3;};
#pragma optimization_level 4
// Original: arm9/main @ 0x020A08D8; symbol: func_020a08d8; size: 0x34.
extern "C" ARM unsigned GameStats_GetCompletionPercentOf944(Record* p){unsigned value=p->c;unsigned result=value*100/944;if(result)return result;if(value)result=1;return result;}

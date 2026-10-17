#include <globaldefs.h>
struct Record{char pad[20];unsigned a:9;unsigned b:9;unsigned c:11;unsigned rest:3;};
#pragma optimization_level 4
// Original: arm9/main @ 0x020A0870; symbol: func_020a0870; size: 0x34.
extern "C" ARM unsigned ComputePercentOf307WithNonzeroMinimumOne(Record* p){unsigned value=p->a;unsigned result=value*100/307;if(result)return result;if(value)result=1;return result;}

#include <globaldefs.h>
struct Counter {unsigned reserved[2];unsigned count:16;unsigned flags:16;};
// Original: arm9/main @ 0x0209FFFC; symbol: func_0209fffc; size: 0x3C.
extern "C" ARM void AddToCounterSaturatingAt65535(Counter* object,unsigned amount) {unsigned count=object->count+amount;if(count>65535)count=65535;object->count=count;}

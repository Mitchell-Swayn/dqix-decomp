#include <globaldefs.h>
ARM
struct Flags {unsigned low:24;unsigned value:2;unsigned high:6;};
// Original: arm9/main @ 0x02068894; symbol: func_02068894; size: 0x1C.
extern "C" unsigned Object_ReadInitialNestedPackedFlag(void*,unsigned char* p){unsigned char* q=*(unsigned char**)p;return q?((Flags*)(q+8))->value:0;}

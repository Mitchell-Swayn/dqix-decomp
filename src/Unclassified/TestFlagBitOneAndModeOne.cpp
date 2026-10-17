#include <globaldefs.h>
ARM
struct Record { unsigned char padding[0x22]; unsigned short mode:2; unsigned short rest:14; };
// Original: arm9/main @ 0x020885B4; symbol: func_020885b4; size: 0x2C.
 extern "C" int TestFlagBitOneAndModeOne(Record* p) { if ((*(unsigned int*)((unsigned char*)p+0x14)&2) && p->mode==1)return 1;return 0; }

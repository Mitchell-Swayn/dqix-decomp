#include <globaldefs.h>
ARM
struct Record { unsigned char padding[0x22];unsigned short low:9;unsigned short mode:3;unsigned short high:4; };
// Original: arm9/main @ 0x02088788; symbol: func_02088788; size: 0x2C.
extern "C" int CombatStatus_HasAttributeWardModeFour(Record* p) { if ((*(unsigned int*)((unsigned char*)p+0x18)&0x80) && p->mode==4)return 1;return 0; }

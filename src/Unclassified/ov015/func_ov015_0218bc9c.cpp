#include <globaldefs.h>
struct Record { char opaque0[8]; unsigned flags; char opaque1[0xae - 12]; unsigned char value; };
// Original: arm9/ov015 @ 0x0218BC9C; symbol: func_ov015_0218bc9c; size: 0x14.
extern "C" ARM int func_ov015_0218bc9c(Record* p){return (p->flags&16)?p->value:-1;}

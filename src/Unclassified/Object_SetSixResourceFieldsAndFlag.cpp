#include <globaldefs.h>
struct Record { unsigned first,second,third; unsigned char flag; unsigned char pad[3]; unsigned fifth,sixth; };
// Original: arm9/main @ 0x020B1D48; symbol: func_020b1d48; size: 0x28.
extern "C" void Object_SetSixResourceFieldsAndFlag(volatile Record* p,unsigned a,unsigned b,unsigned c,unsigned flag,unsigned d,unsigned e) { p->second=b;p->third=c;p->flag=flag;p->first=a;p->sixth=d;p->fifth=e; }

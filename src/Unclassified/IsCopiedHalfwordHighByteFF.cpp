#include <globaldefs.h>
extern "C" {
void *memcpy(void *,const void *,unsigned int);
// Original: arm9/main @ 0x02044494; symbol: func_02044494; size: 0x28.
bool IsCopiedHalfwordHighByteFF(int unused,void *p){unsigned short v;memcpy(&v,p,2);return (v&0xff00)==0xff00;}
}

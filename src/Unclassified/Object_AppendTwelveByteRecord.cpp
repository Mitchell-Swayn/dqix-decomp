#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02027B5C; symbol: func_02027b5c; size: 0x50.
void Object_AppendTwelveByteRecord(unsigned char *p,unsigned short a,unsigned char b,unsigned int c,unsigned int d){char *data=*(char **)(p+0xa9c);if(!data)return;unsigned int count=p[0xa99];if(p[0xa98]<=count)return;char *q=data+count*12;*(unsigned short *)q=a;q[2]=b;*(unsigned int *)(q+4)=c;*(unsigned int *)(q+8)=d;p[0xa99]++;}
}

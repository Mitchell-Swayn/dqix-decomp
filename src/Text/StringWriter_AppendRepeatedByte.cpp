#include <globaldefs.h>
ARM
struct Buffer { unsigned remaining; unsigned char* data; };
// Original: arm9/main @ 0x020D30B4; symbol: func_020d30b4; size: 0x54.
extern "C" void StringWriter_AppendRepeatedByte(Buffer* p,unsigned char value,int count) { if(count<=0)return;unsigned i=0;unsigned n=p->remaining;if(n>(unsigned)count)n=count;if(i<n) { do { p->data[i]=value; ++i; } while(i<n); }p->remaining-=n;p->data+=count; }

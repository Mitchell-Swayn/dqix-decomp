#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02083A50; symbol: func_02083a50; size: 0x7C.
unsigned int EnumerateSetBitsWithinOutputLimit(unsigned char *p,unsigned short *out,unsigned int limit){unsigned int count=0;p+=0x8ec;for(int i=0;i<36;i++)if(p[i])for(int j=0;j<8;j++)if(p[i]&(1<<j)){out[count++]=j+(i<<3);if(count==limit)return count;}return count;}
}

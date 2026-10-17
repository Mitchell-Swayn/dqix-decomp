#include <globaldefs.h>
extern "C" {
void memset(void*,int,unsigned);
}
// Original: arm9/ov006 @ 0x021536E0; symbol: func_ov006_021536e0; size: 0x50.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM void ResetWordAndSentinelByteRecord(char* p)
{
    *(int*)(p)=0;
    *(int*)(p+4)=0;
    *(int*)(p+8)=0;
    *(int*)(p+12)=0;
    *(int*)(p+16)=0;
    memset(p+0x14,-1,6);
    memset(p+0x1a,-1,3);
    *(int*)(p+0x20)=0;
    *(short*)(p+0x24)=0;
}

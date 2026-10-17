#include <globaldefs.h>
ARM
#include <System/Memory.h>
struct Entry{unsigned char pad[28];};
// Original: arm9/main @ 0x020269E4; symbol: func_020269e4; size: 0x44.
extern "C" void CopyNextEntryToCallerAndAdvanceCount(unsigned char* p,void* data){unsigned int count=p[0x780];if(count>=20)return;if(!data)return;Entry* entries=(Entry*)(p+0x784);MI_CpuCopy8(data,entries+count,28);p[0x780]++;}

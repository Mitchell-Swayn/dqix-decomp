#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct Spans { char pad[16];char* first;int firstSize;char* second;int secondSize; };
// Original: arm9/ov031 @ 0x02206758; symbol: func_ov031_02206758; size: 0x98.
extern "C" int CopyAndConsumeTwoBufferSpans(char* dest,int limit,Spans* p){
int first=p->firstSize;int second=p->secondSize;
if(first>limit){first=limit;second=0;}else{int remaining=limit-first;if(second>remaining)second=remaining;}
if(first>0){MI_CpuCopy8(p->first,dest,first);p->first+=first;p->firstSize-=first;}
if(second>0){MI_CpuCopy8(p->second,dest+first,second);p->second+=second;p->secondSize-=second;}
return first+second;
}

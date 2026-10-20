#include <globaldefs.h>
#include <System/Memory.h>
ARM
struct SegmentHeaderRange { unsigned start; unsigned char *source,*destination; unsigned size; };
// Original: arm9/ov027 @ 0x021DA314; symbol: func_ov027_021da314; size: 0x78.
// Copies or zeroes the segment intersection with the protected header interval.
extern "C" void MBi_ReadSegmentHeader(SegmentHeaderRange *segment,unsigned start,unsigned end,int clear)
{
    unsigned size,first;
    first=segment->start;
    size=segment->size;
    if(start<0x4000)start=0x4000;
    if(end>0x8000)end=0x8000;
    if(start<first)start=first;
    if(end>first+size)end=first+size;
    if(start>=end)return;
    if(clear)VectorizedMemset(segment->destination+start,0,end-start);
    else MI_CpuCopy8(segment->source+start,segment->destination+start,end-start);
}

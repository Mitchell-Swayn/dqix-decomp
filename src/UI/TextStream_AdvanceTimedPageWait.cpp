#include "globaldefs.h"
#pragma optimize_for_size off
ARM
extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(void*);extern "C" void TextStream_AdvanceSegmentAndRebuildBuffers(void*);
struct Object{unsigned char data[0x1a00];};
// Original: arm9/main @ 0x02065920; symbol: func_02065920; size: 0x70.
extern "C" void TextStream_AdvanceTimedPageWait(Object*p,unsigned amount){unsigned char*d=p->data;if(d[0x19d0] || *(int*)(d+0x9a0)!=4)return;d[0x912]=0;if(amount<d[0x195f]){d[0x195f]-=amount;return;}d[0x195f]=0;d[0x19ae]=0;d[0x19af]=0;d[0x19cd]=1;*(int*)(d+0x40)=0;*(int*)(d+0x44)=0;Text_ProcessBufferedHalfwordCodesAndResetCounters(p);*(int*)(d+0x9a0)=5;TextStream_AdvanceSegmentAndRebuildBuffers(p);}

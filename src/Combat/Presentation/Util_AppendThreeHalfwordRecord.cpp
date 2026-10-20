#include <globaldefs.h>
ARM
extern "C" void Combat_CopyQueuedActionRequest(unsigned short*,const unsigned short*);
struct ThreeHalfwordRecord { unsigned short values[3]; };
// Original: arm9/ov025 @ 0x021DED50; symbol: func_ov025_021ded50; size: 0x34.
// Appends a three-halfword record to the five-entry queue at 0x76EC and increments its halfword count.
// The queue's broader owner and record meanings remain unresolved.
extern "C" void Util_AppendThreeHalfwordRecord(unsigned char* owner,const unsigned short* source)
{
    if (*(unsigned short*)(owner+0x770a)>=5) return;
    Combat_CopyQueuedActionRequest(((ThreeHalfwordRecord*)(owner+0x76ec))[(*(unsigned short*)(owner+0x770a))++].values,source);
}

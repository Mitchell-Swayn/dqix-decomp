#include <globaldefs.h>
struct TransitionFlagView { unsigned char low:1; unsigned char half:1; unsigned char high:6; };
extern "C" float data_020e8ec4[];
extern "C" void SetLinkedNodeRangeUnlessKindTwo(void*,int,int);
extern "C" void WriteGlobalByteAtStride24(int,int);
// Original: arm9/main @ 0x0209C2E0; symbol: func_0209c2e0; size: 0xCC.
extern "C" ARM void UpdateByteLevelTransitionAndThreeChannels(unsigned char* self,unsigned char value,int duration) { self[0xcd]=value; float scale=((float)(int)self[0xcc]-1.0f)/4.0f; int amount=(int)((float)(unsigned)self[0xcd]*scale); if(((TransitionFlagView*)(self+0xc8))->half) amount/=2; SetLinkedNodeRangeUnlessKindTwo(self+0xbc,amount,duration); SetLinkedNodeRangeUnlessKindTwo(self+0xc0,amount,duration); int channel=(int)((float)(unsigned)self[0xcd]*data_020e8ec4[self[0xcc]-1]); WriteGlobalByteAtStride24(5,channel); WriteGlobalByteAtStride24(7,channel); WriteGlobalByteAtStride24(6,channel); }

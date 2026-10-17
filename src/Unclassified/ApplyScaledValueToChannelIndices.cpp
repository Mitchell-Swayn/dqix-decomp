#include <globaldefs.h>
extern "C" float data_020e7dd4[];extern "C" void WriteGlobalByteAtStride24(int,int);
// Original: arm9/main @ 0x0205E944; symbol: func_0205e944; size: 0xB0.
extern "C" ARM void ApplyScaledValueToChannelIndices(unsigned char* p,int value){*(int*)(p+200)=value;int scaled=(int)(value*data_020e7dd4[p[204]-1]);WriteGlobalByteAtStride24(10,scaled);WriteGlobalByteAtStride24(11,scaled);WriteGlobalByteAtStride24(12,scaled);WriteGlobalByteAtStride24(13,scaled);WriteGlobalByteAtStride24(14,scaled);WriteGlobalByteAtStride24(15,scaled);WriteGlobalByteAtStride24(10,scaled);WriteGlobalByteAtStride24(12,scaled);WriteGlobalByteAtStride24(13,scaled);WriteGlobalByteAtStride24(16,scaled);}

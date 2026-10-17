#include <globaldefs.h>
ARM
extern "C" {
extern unsigned data_ov016_0219d1c0[];
extern unsigned char data_ov016_02195f78[];
void MIi_CpuCopyFast(const void*,void*,unsigned);
}
// Original: arm9/ov016 @ 0x0218FCD4; symbol: func_ov016_0218fcd4; size: 0x7C.
extern "C" void* GetOrCopyDataBlock() {
 if(!data_ov016_0219d1c0[2]) {
  if(data_ov016_0219d1c0[5]>=0x659c) {
   data_ov016_0219d1c0[2]=data_ov016_0219d1c0[6];
   MIi_CpuCopyFast(data_ov016_02195f78,(void*)data_ov016_0219d1c0[6],0x659c);
   data_ov016_0219d1c0[6]+=0x659c;
   data_ov016_0219d1c0[5]-=0x659c;
  } else return data_ov016_02195f78;
 }
 return (void*)data_ov016_0219d1c0[2];
}

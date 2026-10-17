#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" const signed char* data_ov031_0224a2dc;
// Original: arm9/ov031 @ 0x0221AAE4; symbol: func_ov031_0221aae4; size: 0x188.
extern "C" int Network_EncodeSixBitAlphabet(const unsigned char* src,unsigned len,char* dst,unsigned capacity) {
 unsigned required=(len%3 ? 4:0)+(len/3)*4;
 if(!dst)return required;
 if(capacity<required)return -1;
 int chars;
 const unsigned char* end=src+len;
 char* out=dst;
 if(src!=end)do {
  int n=end-src;
  int bits=n*8;
  chars=bits/6+(bits%6!=0);
  if(n>=3)n=3;
  unsigned char bytes[3];
  VectorizedMemset(bytes,0,3);
  MI_CpuCopy8(src,bytes,n);
  out[0]=data_ov031_0224a2dc[bytes[0]>>2];
  if(chars<2)out[1]='*';else {int index=((bytes[0]<<4)&63)|(bytes[1]>>4);out[1]=data_ov031_0224a2dc[index];}
  if(chars<3)out[2]='*';else {int index=((bytes[1]<<2)&63)|(bytes[2]>>6);out[2]=data_ov031_0224a2dc[index];}
  if(chars<4)out[3]='*';else {int index=bytes[2]&63;out[3]=data_ov031_0224a2dc[index];}
  src+=n;out+=4;
 } while(src!=end);
 return out-dst;
}

#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int Math_GetSignificantHalfwordCount(const unsigned short*,int);
extern "C" void VectorizedMemset(void*,int,unsigned int);
extern "C" void Math_AddCarryToHalfwords(unsigned short*,unsigned int,int,int);
// Original: arm9/ov031 @ 0x0220BF5C; symbol: func_ov031_0220bf5c; size: 0x134.
extern "C" void Math_SquareHalfwordInteger(unsigned short* dst,const unsigned short* src,int capacity) {
 register int b,sum,a; unsigned int product;
 int n=Math_GetSignificantHalfwordCount(src,capacity);
 if(capacity>n*2) VectorizedMemset(dst+n*2,0,(capacity-n*2)*2);
 int i=0;
 if(n>0) {
 int k=i;
 do {
  if(k>=capacity) break;
  unsigned int v=src[i];
  unsigned int square=v*v;
  dst[k]=(unsigned short)square;
  if(k==capacity-1) break;
  (dst+k)[1]=(unsigned short)(square>>16);
  i++; k+=2;
 } while(i<n);
 }
 a=0;
 if(n<=0) return;
 do {
  for(b=a+1;b<n && (sum=a+b)<capacity;b++) {
   product=src[b]*src[a];
   if(product<=0x7fff8000) Math_AddCarryToHalfwords(dst,product*2,sum,capacity);
   else { Math_AddCarryToHalfwords(dst,product,sum,capacity);Math_AddCarryToHalfwords(dst,product,sum,capacity); }
  }
  a++;
 } while(a<n);
}

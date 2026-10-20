#include <globaldefs.h>
ARM
#define W(p,o) (*(unsigned*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void* memmove(void*,const void*,unsigned);
extern "C" void Math_SquareHalfwordInteger(unsigned short*,const unsigned short*,int);
extern "C" void Math_MultiplyHalfwordArraysTruncated(unsigned short*,const unsigned short*,const unsigned short*,int);
extern "C" void Math_AddHalfwordArrays(unsigned short*,const unsigned short*,const unsigned short*,int);
extern "C" int CompareHalfwordArraysFromEnd(const unsigned short*,const unsigned short*,int);
extern "C" void Math_SubtractHalfwordIntegers(unsigned short*,const unsigned short*,const unsigned short*,int);
// Original: arm9/ov031 @ 0x0220c59c; symbol: Math_ReduceShiftedHalfwordProduct.
extern "C" void Math_MontgomeryReduceHalfwordProduct(unsigned short* out,const unsigned short* in,unsigned short* multiplier,int count,int shift,const unsigned short* modulus,unsigned short* factor,unsigned short* temp,unsigned short* scratch){
MI_CpuCopy8(out,(void*)in,count*2);
if(multiplier==(unsigned short*)1)Math_SquareHalfwordInteger(out,in,count);else if(multiplier)Math_MultiplyHalfwordArraysTruncated(out,in,multiplier,count);
Math_MultiplyHalfwordArraysTruncated(temp,out,factor,shift);
int bytes=(count-shift)*2;VectorizedMemset(temp+shift,0,bytes);
Math_MultiplyHalfwordArraysTruncated(scratch,temp,modulus,count);
Math_AddHalfwordArrays(out,out,scratch,count);
memmove(out,out+shift,bytes);VectorizedMemset(out+count-shift,0,shift*2);
switch(CompareHalfwordArraysFromEnd(out,modulus,count)){case 0:VectorizedMemset(out,0,count*2);break;case 1:Math_SubtractHalfwordIntegers(out,out,modulus,count);break;}
}

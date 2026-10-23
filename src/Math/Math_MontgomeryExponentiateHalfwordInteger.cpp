#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" {
int Math_GetSignificantHalfwordCount(unsigned short*,int);
void Math_InvertHalfwordIntegerModulo(unsigned short*,unsigned short*,unsigned short*,int,unsigned short*);
void Math_MultiplyHalfwordArraysTruncated(unsigned short*,const unsigned short*,const unsigned short*,int);
void Math_SubtractValueFromHalfwordsAndCopyRemainder(unsigned short*,const unsigned short*,unsigned,int);
void Math_DivideHalfwordIntegers(unsigned short*,unsigned short*,unsigned short*,unsigned short*,int,unsigned short*);
void Math_MontgomeryReduceHalfwordProduct(unsigned short*,const unsigned short*,unsigned short*,int,int,const unsigned short*,unsigned short*,unsigned short*,unsigned short*);
// Original data: ov0310224c994; zero-initialized allocation callback, set at runtime.
extern void* (*SslSendClientHello_UnknownRoleZeroInitializedStorage)(unsigned);
// Original data: ov0310224c9c0; zero-initialized deallocation callback, set at runtime.
extern void (*SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2)(void*);
}
// Original: arm9/ov031 @ 0x0220c6c4; symbol: Math_MontgomeryExponentiateHalfwordInteger; size 0x20c.
extern "C" void Math_MontgomeryExponentiateHalfwordInteger(unsigned short* output,unsigned short* base,unsigned short* exponent,int count,unsigned short* modulus){
 unsigned bytes=count*22;
 unsigned short* power=(unsigned short*)SslSendClientHello_UnknownRoleZeroInitializedStorage(bytes);
 if(!power)return;
 VectorizedMemset(power,0,bytes);
 int shift;
 unsigned bit;
 unsigned short* division;
 unsigned short* factor=power+count;
 unsigned short* reducedBase=factor+count;
 unsigned short* product=reducedBase+count;
 unsigned short* scratch=product+count;
 unsigned short* copy=scratch+count;
 division=copy+count;
 shift=Math_GetSignificantHalfwordCount(modulus,count);
 power[shift]=1;
 Math_InvertHalfwordIntegerModulo(factor,power,modulus,count,reducedBase);
 Math_MultiplyHalfwordArraysTruncated(product,power,factor,count);
 Math_SubtractValueFromHalfwordsAndCopyRemainder(factor,product,1,count);
 Math_DivideHalfwordIntegers(factor,factor,modulus,0,count,division);
 Math_MultiplyHalfwordArraysTruncated(reducedBase,base,power,count);
 Math_DivideHalfwordIntegers(0,reducedBase,modulus,reducedBase,count,division);
 Math_DivideHalfwordIntegers(0,power,modulus,output,count,division);
 bit=0;
 unsigned bits=shift*16;
 for(;bit<bits;++bit){
  Math_MontgomeryReduceHalfwordProduct(output,copy,(unsigned short*)1,count,shift,modulus,factor,product,scratch);
  if(exponent[shift-((int)bit>>4)-1]&(0x8000u>>(bit&15)))
   Math_MontgomeryReduceHalfwordProduct(output,copy,reducedBase,count,shift,modulus,factor,product,scratch);
 }
 Math_MontgomeryReduceHalfwordProduct(output,copy,0,count,shift,modulus,factor,product,scratch);
 SslSendClientHello_UnknownRoleZeroInitializedStorage_Variant2(power);
}

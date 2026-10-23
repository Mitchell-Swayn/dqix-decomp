#include <globaldefs.h>
#include <System/Memory.h>
ARM
#pragma optimize_for_size off
#pragma optimization_level 4
extern "C" {
int Math_GetSignificantHalfwordCount(unsigned short*,int);
unsigned long long Math_LoadTripleLimbDivisionEstimate(const unsigned short*);
unsigned long long Math_LoadDoubleLimbDivisionEstimate(const unsigned short*);
unsigned long long Math_LoadSingleLimbDivisionEstimate(const unsigned short*);
unsigned long long Math_LoadFourLimbDivisionWindow(const unsigned short*);
void* memmove(void*,const void*,unsigned);
void Math_MultiplyHalfwordIntegerByScalar(unsigned short*,unsigned short*,unsigned,int);
int CompareHalfwordArraysFromEnd(const unsigned short*,const unsigned short*,int);
void Math_SubtractHalfwordIntegers(unsigned short*,unsigned short*,unsigned short*,int);
}
// Original: arm9/ov031 @ 0x0220c0dc; symbol: Math_DivideHalfwordIntegers; size 0x1e0.
extern "C" void Math_DivideHalfwordIntegers(unsigned short* quotient,unsigned short* numerator,unsigned short* divisor,unsigned short* remainder,int count,unsigned short* scratch){
 int position;
 unsigned guess;
 int d;
 unsigned short* q=scratch+count;
 unsigned short* r=q+count;
 VectorizedMemset(q,0,count*4);
 int n=Math_GetSignificantHalfwordCount(numerator,count);
 d=Math_GetSignificantHalfwordCount(divisor,count);
 if(n>0 && d>0){
  position=d+(count-n)-1;
  if(position>=count)MI_CpuCopy8(numerator,r,count*2);
  else{
   MI_CpuCopy8(numerator,q+position,n*2);
   unsigned long long estimate;
   if(d>2)estimate=Math_LoadTripleLimbDivisionEstimate(divisor+d-1);
   else if(d>1)estimate=Math_LoadDoubleLimbDivisionEstimate(divisor+d-1);
   else estimate=Math_LoadSingleLimbDivisionEstimate(divisor+d-1);
   for(;position<count;++position){
    memmove(q+1,q,(count*2-1)*2);
    guess=(unsigned)(Math_LoadFourLimbDivisionWindow(r+d)/estimate);
    if(guess>0xffff)guess=0xffff;
    do{
     Math_MultiplyHalfwordIntegerByScalar(scratch,divisor,(unsigned short)guess,count);
     if(CompareHalfwordArraysFromEnd(r,scratch,count)>=0)break;
     --guess;
    }while(1);
    Math_SubtractHalfwordIntegers(r,r,scratch,count);
    q[0]=(unsigned short)guess;
   }
  }
 }
 if(quotient)MI_CpuCopy8(q,quotient,count*2);
 if(remainder)MI_CpuCopy8(r,remainder,count*2);
}

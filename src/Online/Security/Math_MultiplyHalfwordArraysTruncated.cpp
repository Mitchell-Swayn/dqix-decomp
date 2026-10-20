#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" int Math_GetSignificantHalfwordCount(const unsigned short*,int);
extern "C" void Math_AddCarryToHalfwords(unsigned short*,unsigned,int,int);
// Original: arm9/ov031 @ 0x0220BE38; symbol: func_ov031_0220be38; size: 0xAC.
extern "C" void Math_MultiplyHalfwordArraysTruncated(unsigned short* output,const unsigned short* a,const unsigned short* b,int length){
 VectorizedMemset(output,0,length*2);
 int countB;
 int countA=Math_GetSignificantHalfwordCount(a,length);
 countB=Math_GetSignificantHalfwordCount(b,length);
 for(int j=0;j<countB;j++){
 for(int i=0;i<countA && i<length-j;i++){
 Math_AddCarryToHalfwords(output,a[i]*b[j],j+i,length);
 }
 }
}

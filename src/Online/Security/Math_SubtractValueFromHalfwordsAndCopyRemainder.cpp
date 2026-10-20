#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original: arm9/ov031 @ 0x0220BD64; symbol: func_ov031_0220bd64; size: 0x68.
// Subtracts an initial value with halfword borrow propagation, then copies remaining halfwords when buffers differ.
extern "C" void Math_SubtractValueFromHalfwordsAndCopyRemainder(unsigned short *dest,const unsigned short *source,unsigned borrow,int count) {
 int index=0;
 if(count>0)do {
 unsigned value=source[index]-borrow;
 borrow=value>>16;
 dest[index]=value;
 borrow&=1;
 if(!borrow)break;
 ++index;
 }while(index<count);
 if(dest==source)return;
 ++index;
 if(index>=count)return;
 do {
 dest[index]=source[index];
 ++index;
 }while(index<count);
}

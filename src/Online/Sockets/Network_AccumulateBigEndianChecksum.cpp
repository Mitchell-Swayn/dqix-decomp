#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022005B4; symbol: func_ov031_022005b4; size: 0xB4.
extern "C" unsigned short Network_AccumulateBigEndianChecksum(unsigned char* p,unsigned int length,unsigned int sum) {
if((unsigned int)p&1){
if(length>1)do {sum+=(unsigned short)((p[0]<<8)|p[1]);length-=2;p+=2;}while(length>1);
}else{
unsigned short initial=(unsigned short)sum;
sum=(unsigned short)((initial>>8)|(initial<<8));
if(length>1)do {sum+=*(unsigned short*)p;p+=2;length-=2;}while(length>1);
unsigned int swapped=((sum>>8)&0x00ff00ff)|((sum<<8)&0xff00ff00);
sum=(swapped>>16)|(swapped<<16);
}
if(length)sum+=*p<<8;
sum=(unsigned short)sum+(sum>>16);
sum+=sum>>16;
return (unsigned short)sum;
}

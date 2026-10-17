#include <globaldefs.h>
ARM
extern "C" int _s32_div_f(int,int);
// Original: arm9/main @ 0x0203A48C; symbol: func_0203a48c; size: 0xC0.
extern "C" void AppendNumberDisplayEntryWithDigitCount(char* p,int value,const int* position,unsigned char a,unsigned b,unsigned c){int digits=0;int n=value;while(n>0){n=_s32_div_f(n,10);++digits;}if(!digits)return;int stride=*(int*)(p+1748)*24;char* e=p+1360+stride;e[5]=37;*(short*)(p+1360+stride)=value;*(int*)(e+12)=position[0];*(int*)(e+16)=position[1];*(int*)(e+20)=position[2];e[4]=b;*(unsigned short*)(e+2)=c;e[6]=digits;*(unsigned short*)(e+8)=819;*(unsigned short*)(e+10)=4915;e[7]=a;int next=*(int*)(p+1748)+1;*(int*)(p+1748)=next;if(next>=16)*(int*)(p+1748)=0;}

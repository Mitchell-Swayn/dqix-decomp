#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct Flags {unsigned char a:2,b:1,c:3,d:1,e:1;};
// Original: arm9/main @ 0x0206BF2C; symbol: func_0206bf2c; size: 0xE4.
extern "C" void InitializeRecordAndInvalidHalfwordIndices(char* p){
 *p=0;*(short*)(p+2)=0;p[4]=0;p[5]=0;p[7]=0;p[8]=0;Flags* flags=(Flags*)(p+10);flags->a=0;flags->b=0;flags->c=0;flags->d=0;flags->e=0;
 *(int*)(p+12)=0;p[11]=0;p[30]=0;memset(p+36,0,16);p[31]=0;*(int*)(p+52)=0;*(int*)(p+56)=122;*(int*)(p+60)=0;*(int*)(p+64)=0;*(short*)(p+68)=0;*(short*)(p+70)=-1;memset(p+16,0,12);*(short*)(p+28)=0;memset(p+72,0,12);*(int*)(p+84)=0;*(int*)(p+88)=0;*(int*)(p+92)=0;*(int*)(p+96)=0;*(short*)(p+32)=0;*(int*)(p+100)=0;*(int*)(p+104)=0;*(int*)(p+108)=0;*(int*)(p+112)=0;
}

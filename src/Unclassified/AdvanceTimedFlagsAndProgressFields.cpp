#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020657C8; symbol: func_020657c8; size: 0xE4.
extern "C" int AdvanceTimedFlagsAndProgressFields(unsigned char* p,int delta){
 unsigned char flags=p[0x195b];int result=0;
 if((flags&4)&&!*(int*)(p+0x9a0)){
 if(flags&8){int value=delta*0x8444+*(int*)(p+0x9b0);*(int*)(p+0x9b0)=value;if(value>=0x1f0000){*(int*)(p+0x9b0)=0x1f0000;*(int*)(p+0x9ac)=0;p[0x195b]&=~8;p[0x195b]|=16;}}
 else if(flags&16){int value=*(int*)(p+0x9ac)+delta;*(int*)(p+0x9ac)=value;if(*(int*)(p+0x9a8)<=value){*(int*)(p+0x9ac)=*(int*)(p+0x9a8);p[0x195b]&=~16;p[0x195b]|=32;}}
 else if(flags&32){int value=*(int*)(p+0x9b0)-delta*0x8444;*(int*)(p+0x9b0)=value;if(value<=0){*(int*)(p+0x9b0)=0;p[0x195b]&=~32;}}
 result=1;}return result;
}

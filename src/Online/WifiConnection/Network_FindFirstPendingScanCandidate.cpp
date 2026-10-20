#include <globaldefs.h>
ARM
struct HighFlag{unsigned char low:7;unsigned char set:1;};
// Original: arm9/ov031 @ 0x022148E4; symbol: func_ov031_022148e4; size: 0x44.
// Returns the first index whose fourth entry byte has bit7 clear; defaults to0.
extern "C" int Network_FindFirstPendingScanCandidate(unsigned char* self){
 unsigned char index;
 int result;
 unsigned count=self[0xd12];
 result=0;
 index=0;
 if(index<count)do{
  if(!((HighFlag*)(self+0x447+index*4))->set){result=index;break;}
  index++;
 }while(index<count);
 return result;
}

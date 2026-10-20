#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original: arm9/main @ 0x020839DC; symbol: func_020839dc; size: 0x74.
extern "C" int CharacterState_EnumerateLearnedSpells(unsigned char* p,unsigned char* output,int maximum){int count=0;unsigned char* bits=p+0x910;for(int i=0;i<9;i++){if(!bits[i])continue;for(int j=0;j<8;j++)if(bits[i]&(1U<<j)){output[count++]=j+i*8;if(count==maximum)return count;}}return count;}

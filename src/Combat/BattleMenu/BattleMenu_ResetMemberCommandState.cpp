#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
// Original: arm9/ov000 @ 0x0216FE9C; symbol: func_ov000_0216fe9c; size: 0x84.
extern "C" void BattleMenu_ResetMemberCommandState(char* p) {
*(short*)(p)=1;
*(short*)(p+2)=1;
*(short*)(p+4)=1;
*(short*)(p+6)=1;
memset(p+8,0,8);
p[8]=13;
p[16]=0;
p[17]=0;
p[19]=0;
p[20]=-1;
p[21]=-1;
p[24]=-1;
*(short*)(p+22)=-1;
p[25]=-1;
p[26]=-1;
p[27]=-1;
p[28]=0;
p[29]=0;
*(unsigned int*)(p+32)=0;
*(short*)(p+36)=-1;
p[38]=-1;
*(short*)(p+30)=0;
p[39]=0;
}

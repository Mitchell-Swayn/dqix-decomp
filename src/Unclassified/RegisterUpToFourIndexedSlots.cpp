#include <globaldefs.h>
ARM
extern "C" unsigned char data_020fdcce[];
// Original: arm9/main @ 0x02026348; symbol: func_02026348; size: 0x4C.
extern "C" void RegisterUpToFourIndexedSlots(unsigned char* p,unsigned char* ids,int count){if((unsigned)count>4){p[0x75c]=0;return;}for(int i=0;i<count;){unsigned char id=ids[i];unsigned char* slot=p+i;++i;slot[0x758]=id;data_020fdcce[id*32]=1;}p[0x75c]=count;}

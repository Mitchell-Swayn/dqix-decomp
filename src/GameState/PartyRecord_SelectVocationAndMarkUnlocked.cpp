#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02086598; symbol: func_02086598; size: 0x18.
void PartyRecord_SelectVocationAndMarkUnlocked(char *p,unsigned int i){*(unsigned short *)(p+0x54)|=1<<i;*(unsigned int *)(p+0x50)=i;}
}

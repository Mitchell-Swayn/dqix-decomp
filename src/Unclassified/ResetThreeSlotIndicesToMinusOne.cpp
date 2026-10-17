#include <globaldefs.h>
struct Slots{int reserved[2];int slot[3];};
// Original: arm9/main @ 0x020B033C; symbol: func_020b033c; size: 0x20.
extern "C" ARM void ResetThreeSlotIndicesToMinusOne(Slots* p){int i=0;do{p->slot[i]=-1;++i;}while(i<3);}

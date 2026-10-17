#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02048228; symbol: func_02048228; size: 0x38.
extern "C" int AdvanceHalfwordCounterTowardSourceTotal(unsigned char* p,int amount){unsigned short* dst=*(unsigned short**)(p+0x130);unsigned char* src=*(unsigned char**)(p+0x134);int old=dst[2];int total=*(unsigned short*)(src+48);int delta=total-old;if(delta<=0)return 0;if(delta<=amount)dst[2]=total;else {dst[2]=old+amount;delta=amount;}return delta;}

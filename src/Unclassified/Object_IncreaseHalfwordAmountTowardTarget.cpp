#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x02048284; symbol: func_02048284; size: 0x38.
int Object_IncreaseHalfwordAmountTowardTarget(unsigned short **p,int amount){unsigned short *q=p[76];int old=q[3];int target=p[77][25];int delta=target-old;if(delta<=0)return 0;if(delta<=amount)q[3]=target;else{q[3]=old+amount;delta=amount;}return delta;}
}

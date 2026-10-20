#include <globaldefs.h>
ARM


// Original: arm9/main @ 0x020482E0; symbol: func_020482e0; size: 0x70.
extern "C" unsigned GameObject_SubtractHPWithOptionalDeath(int object,int amount,int permitEmpty){int state=*(int*)(object+0x130);unsigned count=*(unsigned short*)(state+4);if((int)count<=amount){if(!permitEmpty){*(unsigned short*)(state+4)=1;return count-1;}permitEmpty=0;*(unsigned short*)(state+4)=permitEmpty;unsigned previous=**(unsigned**)(object+0x130);if(previous&4)permitEmpty=1;**(unsigned**)(object+0x130)=1;if(permitEmpty)**(unsigned**)(object+0x130)|=4;return count;}*(unsigned short*)(state+4)=count-amount;return amount;}

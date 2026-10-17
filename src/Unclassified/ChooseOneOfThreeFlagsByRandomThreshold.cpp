#include <globaldefs.h>
ARM
extern "C" int rand();
// Original: arm9/main @ 0x020DE0EC; symbol: func_020de0ec; size: 0x50.
extern "C" void ChooseOneOfThreeFlagsByRandomThreshold(unsigned char* object){int n=rand()%10000;object[0x24]=0;if(n<25){object[0x24]|=4;return;}if(n<200)object[0x24]|=2;else object[0x24]|=1;}

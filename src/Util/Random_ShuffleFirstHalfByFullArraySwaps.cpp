#include <globaldefs.h>
extern "C" int rand();
// Original: arm9/main @ 0x0203232C; symbol: func_0203232c; size: 0x44.
extern "C" ARM void Random_ShuffleFirstHalfByFullArraySwaps(unsigned* p,int count){for(int i=0;i<count/2;i++){int j=rand()%count;unsigned v=p[i];p[i]=p[j];p[j]=v;}}

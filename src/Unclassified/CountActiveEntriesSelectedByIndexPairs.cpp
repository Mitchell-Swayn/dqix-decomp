#include <globaldefs.h>
ARM
extern "C" signed char data_020e8b5a[]; extern "C" signed char data_020e8b5b[];
struct Flags { unsigned pad:15; unsigned active:1; };
// Original: arm9/main @ 0x02085318; symbol: func_02085318; size: 0x74.
extern "C" int CountActiveEntriesSelectedByIndexPairs(char *self) { int result,i=0,index; result=0; while((index=data_020e8b5a[i*2])!=-1) { if(*(short *)(self+data_020e8b5b[i+i]*32+0x1ac)>0 && ((Flags *)(self+index*44+0x2f4))->active) ++result; ++i; } return result; }

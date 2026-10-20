#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020C01AC; symbol: func_020c01ac; size: 0x40.
extern "C" void* NNSi_SndSeqArcGetSeqInfo(unsigned char* p,int index){if(index<0)return 0;if((unsigned)index>=*(unsigned*)(p+28))return 0;unsigned char* entry=p+32+index*12;return *(int*)entry==-1?0:entry;}

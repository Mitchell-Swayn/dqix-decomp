#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" int Object_TestNewlySetHalfwordMask(void*,unsigned);extern "C" unsigned char data_02114e30[];
// Original: arm9/main @ 0x02045740; symbol: func_02045740; size: 0xA0.
extern "C" void UpdateWrappedSelectionFromInputFlags(int* p){p[0x958/4]=(p[0x958/4]+1)&31;if(Object_TestNewlySetHalfwordMask(data_02114e30,64)){int n=p[0x954/4]-1;p[0x954/4]=n;if(n<0)p[0x954/4]=p[0x9a4/4]-1;p[0x994/4]=p[0x954/4];p[0x958/4]=0;return;}if(!Object_TestNewlySetHalfwordMask(data_02114e30,128))return;int n=p[0x954/4]+1;p[0x954/4]=n;if(n>=p[0x9a4/4])p[0x954/4]=0;p[0x994/4]=p[0x954/4];p[0x958/4]=0;}

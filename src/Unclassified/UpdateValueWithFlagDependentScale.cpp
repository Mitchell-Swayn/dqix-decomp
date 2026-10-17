#include <globaldefs.h>
ARM
extern "C" {void func_0203cbd8(void*);void func_0203f53c(void*,int,int);
// Original: arm9/main @ 0x0203CD64; symbol: func_0203cd64; size: 0x44.
void UpdateValueWithFlagDependentScale(unsigned char* p,int value){unsigned int flags=*(unsigned int*)(p+0x5c);if(!(flags&0x10)&&!(flags&0x20))func_0203cbd8(p);func_0203f53c(p,value,p[0x95]?0xe40:0x1000);}}

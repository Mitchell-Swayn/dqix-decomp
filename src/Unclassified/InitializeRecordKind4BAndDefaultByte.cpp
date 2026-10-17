#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(void*);
// Original: arm9/main @ 0x020DAC68; symbol: func_020dac68; size: 0x2C.
extern "C" void InitializeRecordKind4BAndDefaultByte(unsigned char* p){InitializeFourWordsWithInvalidIndex(p);p[0]=75;*(int*)(p+12)=0;*(int*)(p+16)=0;p[40]=255;}

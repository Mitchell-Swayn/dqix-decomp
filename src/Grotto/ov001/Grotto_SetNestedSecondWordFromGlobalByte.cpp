#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x0215E374; symbol: func_ov001_0215e374; size: 0x24.
extern "C" int Grotto_SetNestedSecondWordFromGlobalByte(void* p) { unsigned char value = *((unsigned char*)((char*)ReadWordFieldAtOffset1C() + 0x19bd)); SetNestedSecondWordForTypeThree(p, value); return 1; }

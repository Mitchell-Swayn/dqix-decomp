#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
// Original: arm9/ov001 @ 0x0215E3B8; symbol: func_ov001_0215e3b8; size: 0x30.
extern "C" int Grotto_SetNestedSecondWordFromGlobalByteIfPresent(void* p) { unsigned int base = ReadWordFieldAtOffset1C(); if (!base) return 0; int value = *((unsigned char*)((char*)base + 0x19b4)); SetNestedSecondWordForTypeThree(p, value); return 1; }

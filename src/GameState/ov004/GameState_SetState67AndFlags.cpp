#include <globaldefs.h>
ARM
extern "C" void func_ov011_021848a0(void*, unsigned int);
extern "C" unsigned int ReadWordFieldAtOffset1C(void);
extern "C" unsigned int data_ov004_02171048[];
// Original: arm9/ov004 @ 0x0216F824; symbol: func_ov004_0216f824; size: 0x30.
extern "C" int GameState_SetState67AndFlags(void* self) { func_ov011_021848a0(self, 0x67); *(unsigned int*)((char*)ReadWordFieldAtOffset1C() + 0x2c8) = 1; *((unsigned char*)(unsigned int)data_ov004_02171048[1] + 0x31) = 1; return 0; }

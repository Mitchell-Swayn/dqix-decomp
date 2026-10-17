#include <globaldefs.h>
ARM
extern "C" void func_ov031_02211acc(void);
extern "C" unsigned int data_ov031_0224e598[];
// Original: arm9/ov031 @ 0x02211820; symbol: func_ov031_02211820; size: 0x28.
extern "C" void System_ResetGlobalPairUnlessStateNine(void) { func_ov031_02211acc(); if (data_ov031_0224e598[0] != 9) { data_ov031_0224e598[0] = 0; data_ov031_0224e598[1] = 0; } }

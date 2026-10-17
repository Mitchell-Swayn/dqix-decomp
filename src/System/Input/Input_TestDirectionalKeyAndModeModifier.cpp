#include <globaldefs.h>
extern "C" unsigned char data_02114e30[]; extern "C" int Input_TestKeyMask(void*,unsigned);
// Original: arm9/main @ 0x0202A9F4; symbol: func_0202a9f4; size: 0xA0.
extern "C" ARM int Input_TestDirectionalKeyAndModeModifier(const char* state) { switch(*(int*)(state+64)) { case 0: if(Input_TestKeyMask(data_02114e30,64)) return 1; case 1: if(Input_TestKeyMask(data_02114e30,64)&&Input_TestKeyMask(data_02114e30,1024)) return 1; case 2: if(Input_TestKeyMask(data_02114e30,64)&&Input_TestKeyMask(data_02114e30,2048)) return 1; } return 0; }

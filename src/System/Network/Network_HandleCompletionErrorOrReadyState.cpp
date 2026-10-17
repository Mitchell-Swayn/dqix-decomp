#include <globaldefs.h>
ARM
extern "C" unsigned char data_021015a0[];extern "C" void SetGlobalValueExceptModesNineAndTen(int);
// Original: arm9/main @ 0x0202CD28; symbol: func_0202cd28; size: 0x28.
extern "C" void Network_HandleCompletionErrorOrReadyState(unsigned short* p){unsigned id=p[1];if(!id){*(int*)(data_021015a0+16)=1;return;}SetGlobalValueExceptModesNineAndTen(id);}

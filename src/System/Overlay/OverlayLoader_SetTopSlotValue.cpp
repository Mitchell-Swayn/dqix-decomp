#include <globaldefs.h>
ARM
extern "C" volatile unsigned char data_02109da4[]; extern "C" unsigned char data_02109da6[];
// Original: arm9/main @ 0x020A1FD4; symbol: func_020a1fd4; size: 0x28.
 extern "C" void OverlayLoader_SetTopSlotValue(unsigned char value) { if (data_02109da4[1]) data_02109da6[data_02109da4[1]-1]=value; }

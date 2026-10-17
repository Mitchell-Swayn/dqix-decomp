#include <globaldefs.h>
ARM
extern "C" unsigned char data_02110370[];
// Original: arm9/main @ 0x020BD42C; symbol: func_020bd42c; size: 0x18.
extern "C" unsigned int ResourceManager_ExchangeGlobalValue(unsigned int value) { unsigned int old=*(unsigned int*)data_02110370; *(unsigned int*)data_02110370=value; return old; }

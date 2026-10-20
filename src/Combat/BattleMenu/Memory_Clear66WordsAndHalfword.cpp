#include <globaldefs.h>
ARM
// Original: arm9/ov000 @ 0x02171614; symbol: func_ov000_02171614; size: 0x2C.
extern "C" void Memory_Clear66WordsAndHalfword(void* p) { for (int i = 0; i < 0x42; i++) *(unsigned int*)((char*)p + 0x9c + i * 4) = 0; *(unsigned short*)((char*)p + 0x82) = 0; }

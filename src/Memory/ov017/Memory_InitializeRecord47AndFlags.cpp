#include <globaldefs.h>
ARM
extern "C" void InitializeFourWordsWithInvalidIndex(signed char*);
// Original: arm9/ov017 @ 0x021C316C; symbol: func_ov017_021c316c; size: 0x28.
extern "C" void Memory_InitializeRecord47AndFlags(unsigned char* p, unsigned int value) { InitializeFourWordsWithInvalidIndex((signed char*)p); p[0] = 0x47; p[8] = 0; p[9] = value; }

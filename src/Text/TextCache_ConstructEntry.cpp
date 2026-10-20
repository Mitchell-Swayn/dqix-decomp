#include <globaldefs.h>
ARM
extern "C" void TextCache_ResetEntry(void*);
// Original: arm9/main @ 0x0203BE64; symbol: func_0203be64; size: 0x14.
extern "C" void* TextCache_ConstructEntry(void* p){TextCache_ResetEntry(p);return p;}

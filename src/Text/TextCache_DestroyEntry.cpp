#include <globaldefs.h>
extern "C" {
void TextCache_ResetEntry(void *);
// Original: arm9/main @ 0x0203BE78; symbol: func_0203be78; size: 0x14.
void *TextCache_DestroyEntry(void *p){TextCache_ResetEntry(p);return p;}
}

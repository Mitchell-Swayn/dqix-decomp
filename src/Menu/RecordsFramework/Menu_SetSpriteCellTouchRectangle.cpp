#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021FB25C; symbol: func_ov023_021fb25c; size: 0x18.
extern "C" void Menu_SetSpriteCellTouchRectangle(void* p, unsigned short a, unsigned short b, unsigned short c, unsigned int d) { *(unsigned short*)((char*)p + 0x30) = a; *(unsigned short*)((char*)p + 0x32) = b; *(unsigned short*)((char*)p + 0x34) = c; *(unsigned short*)((char*)p + 0x36) = d; }

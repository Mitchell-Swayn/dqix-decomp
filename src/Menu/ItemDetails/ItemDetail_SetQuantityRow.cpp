#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021DCEAC; symbol: func_ov023_021dceac; size: 0x28.
extern "C" void ItemDetail_SetQuantityRow(char* base, unsigned int index, unsigned int value, unsigned char a, unsigned char b, unsigned char c) { *(unsigned int*)(base + index * 4 + 0x784) = value; *(unsigned char*)(base + index + 0x790) = a; *(unsigned char*)(base + index + 0x793) = b; *(unsigned char*)(base + index + 0x796) = c; }

#include <globaldefs.h>
// Original: arm9/ov011 @ 0x021861E4; symbol: func_ov011_021861e4; size: 0x2C.
extern "C" void Graphics_WriteDisplayRegister0400000EControlFields(unsigned a, unsigned b, unsigned c, unsigned d) { volatile unsigned short* reg=(volatile unsigned short*)0x0400000E; *reg=(*reg & 0x43) | (a<<14) | (b<<7) | (c<<8) | (d<<2); }

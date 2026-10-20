#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EC368; symbol: Graphics_ConfigureSubBackgroundOneTextLayout; size: 0x34.
// Configures the text background-one control register on the sub display.
extern "C" void Graphics_ConfigureSubBackgroundOneTextLayout(unsigned screenSize, unsigned colors, unsigned screenBase, unsigned charBase, unsigned extPalette) {
 volatile unsigned short* control = (volatile unsigned short*)0x0400100a;
 *control = (*control & 0x43) | screenSize << 14 | colors << 7 | screenBase << 8 | charBase << 2 | extPalette << 13;
}

#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" void Graphics_DrawColoredRotatedBox(Vec,unsigned,int,int,int,short);
// Original: arm9/main @ 0x0208B5B4; symbol: Graphics_DrawColoredRotatedBoxFromBasePosition; size: 0x5c.
// Raises the by-value position by half the signed scale height before drawing.
// Angle is sign-extended from its stack halfword; color is zero-extended.
extern "C" void Graphics_DrawColoredRotatedBoxFromBasePosition(Vec position,Vec scale,short angle,unsigned short color) {
 position.y+=scale.y/2;
 Graphics_DrawColoredRotatedBox(position,color,scale.x,scale.y,scale.z,angle);
}

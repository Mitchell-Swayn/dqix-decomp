#include <globaldefs.h>
ARM
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(void*,int);
// Original: arm9/main @ 0x0203B540; symbol: func_0203b540; size: 0x3C.
extern "C" void Graphics_WriteMainAndSubPolygonAttributes(float* object){Graphics_WriteSignedBrightnessMagnitudeAndMode((void*)0x0400006c,(int)object[3]);Graphics_WriteSignedBrightnessMagnitudeAndMode((void*)0x0400106c,(int)object[6]);}

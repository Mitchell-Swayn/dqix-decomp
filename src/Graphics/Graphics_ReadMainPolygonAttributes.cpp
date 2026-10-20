#include <globaldefs.h>
ARM
#pragma optimization_level 4
#pragma force_active on
extern "C" int Graphics_DecodeSignedBrightness(volatile unsigned short*);
// Original: arm9/main @ 0x020DBFF4; symbol: func_020dbff4; size: 0x14.
extern "C" int Graphics_ReadMainPolygonAttributes(){return Graphics_DecodeSignedBrightness((volatile unsigned short*)0x0400006c);}

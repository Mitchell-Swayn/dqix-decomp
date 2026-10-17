#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020858F8; symbol: func_020858f8; size: 0x38.
extern "C" float ReadSignedSixBitScaleFromWord2FCHighBitsDividedByTen(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;int value=(*(int*)(object+0x2fc)<<2)>>26;return (float)value/10.0f;}

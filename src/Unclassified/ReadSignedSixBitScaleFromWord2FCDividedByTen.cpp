#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02085850; symbol: func_02085850; size: 0x38.
extern "C" float ReadSignedSixBitScaleFromWord2FCDividedByTen(unsigned char* object){if(*(short*)(object+0x2ac)<=0)return 1.0f;int value=(*(int*)(object+0x2fc)<<20)>>26;return (float)value/10.0f;}

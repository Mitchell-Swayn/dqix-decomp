#include <globaldefs.h>
extern "C" float data_020e88f8[][2];
// Original: arm9/main @ 0x02074738; symbol: func_02074738; size: 0x2C.
extern "C" ARM float Object_ReadLookupFloatClampedToOne(int a,int b){float value=data_020e88f8[a][b];if(value<1.0f)value=1.0f;return value;}

#pragma optimize_for_size off
#include <globaldefs.h>
// Original: arm9/main @ 0x0203B57C; symbol: func_0203b57c; size: 0x24.
extern "C" ARM int ReadSelectedFloatFieldAsInteger(char* object,int alternate){switch(alternate){case 0:return (int)*(float*)(object+12);default:return (int)*(float*)(object+24);}}

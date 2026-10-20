#include <globaldefs.h>
#pragma optimize_for_size off
// Original: arm9/main @ 0x0203B5F8; symbol: func_0203b5f8; size: 0x30.
extern "C" ARM bool GameResources_IsSelectedScreenBrightnessNeutral(char* p,int second){int value;if(second==0)value=(int)*(float*)(p+12);else value=(int)*(float*)(p+24);return value==0;}

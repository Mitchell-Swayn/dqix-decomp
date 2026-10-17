#include <globaldefs.h>
extern "C" void* GameResources_GetInstance();extern "C" int ReadSelectedFloatFieldAsInteger(void*,int);extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);extern "C" int abs(int);
#pragma optimization_level 2
#pragma optimize_for_size off
// Original: arm9/main @ 0x02021428; symbol: func_02021428; size: 0xC8.
extern "C" ARM void Graphics_AdvanceSubBrightnessTowardExtreme(int ignored,int duration){void* p=GameResources_GetInstance();int value=ReadSelectedFloatFieldAsInteger(p,1);if(value-1<=-16){_Z16SetSubBrightnessP13GameResourcesii(p,-16,0);return;}if(value+1>=16){_Z16SetSubBrightnessP13GameResourcesii(p,16,0);return;}if(value>0){if(value<0)value=0;if(value)duration/=abs(value);_Z16SetSubBrightnessP13GameResourcesii(p,16,duration);return;}if(value>0)value=0;if(value)duration/=abs(value);_Z16SetSubBrightnessP13GameResourcesii(p,-16,duration);}

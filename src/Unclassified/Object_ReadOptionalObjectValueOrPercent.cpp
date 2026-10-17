#include <globaldefs.h>
struct Owner{int a;char* object;};
#pragma optimization_level 4
// Original: arm9/main @ 0x0209FCCC; symbol: func_0209fccc; size: 0x34.
extern "C" ARM int Object_ReadOptionalObjectValueOrPercent(Owner* p,int percent){unsigned short* value=*(unsigned short**)(p->object+0x8e18);if(!value)return -1;if(percent)return *value/100;return *value;}

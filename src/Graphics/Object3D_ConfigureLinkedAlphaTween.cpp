#pragma thumb off
#pragma optimization_level 2
#include <World/Object3D.h>
struct AlphaBits{unsigned char value:5,other:3;};
// Original: arm9/main @ 0x02049F50; symbol: func_02049f50; size: 0x70.
extern "C" void Object3D_ConfigureLinkedAlphaTween(char* object,int alpha,int duration){if(duration<=0)((AlphaBits*)(object+0x41))->value=(unsigned char)alpha;char* model=*(char**)(object+0x13c);if(!model)return;float current=(float)((Object3D*)object)->GetOwnAlpha();((AlphaTween*)(*(char**)(object+0x13c)+0x60))->SetCurrentValue(current);((AlphaTween*)(*(char**)(object+0x13c)+0x60))->ConfigureTween(alpha,duration);}

#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" void* Zone3D_GetMainInstance();
extern "C" unsigned char* _ZN6Zone3D20FindLastBMDJInstanceEii(void*,int,int);
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" float Script_ReadParameterAsFloat(FloatParameterView*);
// Original: arm9/ov001 @ 0x02163F60; symbol: func_ov001_02163f60; size: 0xA4.
extern "C" int Script_SetBMDJInstanceFixedPointVector(unsigned char* parameters) {
int first=Script_ReadParameterAsInteger((IntegerParameterView*)parameters);
int second=Script_ReadParameterAsInteger((IntegerParameterView*)(parameters+8));
void* zone=Zone3D_GetMainInstance();
if(!zone)return 0;
unsigned char* instance=_ZN6Zone3D20FindLastBMDJInstanceEii(zone,first,second);
if(!instance)return 0;
*(int*)(instance+0x14)=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+16)));
*(int*)(instance+0x18)=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+24)));
*(int*)(instance+0x1c)=(int)(4096.0f*Script_ReadParameterAsFloat((FloatParameterView*)(parameters+32)));
return 1;
}

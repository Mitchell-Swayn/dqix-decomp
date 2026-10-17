#include <globaldefs.h>
ARM
struct IntegerParameterView; struct FloatParameterView;
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" unsigned char* _ZN6Zone3D20FindLastBMDJInstanceEii(void*,int,int);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
// Original: arm9/ov001 @ 0x02163F60; symbol: func_ov001_02163f60; size: 0xA4.
extern "C" int Script_SetBMDJInstanceFixedPointVector(unsigned char* parameters) {
int first=ReadScriptParameterAsInteger((IntegerParameterView*)parameters);
int second=ReadScriptParameterAsInteger((IntegerParameterView*)(parameters+8));
void* zone=ReadGlobalValueAt020FB3F0();
if(!zone)return 0;
unsigned char* instance=_ZN6Zone3D20FindLastBMDJInstanceEii(zone,first,second);
if(!instance)return 0;
*(int*)(instance+0x14)=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+16)));
*(int*)(instance+0x18)=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+24)));
*(int*)(instance+0x1c)=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(parameters+32)));
return 1;
}

#include <globaldefs.h>
ARM
struct IntegerParameterView;struct FloatParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" unsigned char* _ZN6Zone3D20FindLastBMDJInstanceEii(void*,int,int);
// Original: arm9/ov001 @ 0x02163E50; symbol: func_ov001_02163e50; size: 0xA4.
extern "C" int World_ScriptSetBMDJInstanceFixedPointVector(unsigned char* p){
 int first=ReadScriptParameterAsInteger((IntegerParameterView*)p);
 int second=ReadScriptParameterAsInteger((IntegerParameterView*)(p+8));
 void* zone=ReadGlobalValueAt020FB3F0();
 if(!zone)return 0;
 unsigned char* instance=_ZN6Zone3D20FindLastBMDJInstanceEii(zone,first,second);
 if(!instance)return 0;
 *(int*)(instance+8)=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(p+16));
 *(int*)(instance+12)=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(p+24));
 *(int*)(instance+16)=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(p+32));
 return 1;
}

#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};struct FloatParameterView;struct IntegerParameterView;
extern "C" void* memset(void*,int,unsigned);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void Pool_InitializeConfiguredNode(void*,Vec,unsigned);
extern "C" unsigned char data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215D4BC; symbol: func_ov001_0215d4bc; size: 0xA4.
extern "C" int Resource_ScriptInitializePoolWithFixedPointVector(unsigned char* p){
 Vec v;memset(&v,0,12);
 v.x=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)p);
 v.y=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(p+8));
 v.z=4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(p+16));
 int mode=ReadScriptParameterAsInteger((IntegerParameterView*)(p+24));
 Pool_InitializeConfiguredNode(*(void**)(data_ov001_02165880+0x24),v,mode);
 return 1;
}

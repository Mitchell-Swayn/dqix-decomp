#include <globaldefs.h>
ARM
struct FloatParameterView;struct IntegerParameterView;
struct FixedVector {int x,y,z;};
extern "C" void* memset(void*,int,unsigned);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void func_ov001_02158fc4(void*,FixedVector,unsigned);
extern "C" char data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215D418; symbol: func_ov001_0215d418; size: 0xA4.
extern "C" int Resource_QueueScriptVectorAndInteger(char* args) {
FixedVector vector;
memset(&vector,0,12);
vector.x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)args));
vector.y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+8)));
vector.z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+16)));
unsigned value=ReadScriptParameterAsInteger((IntegerParameterView*)(args+24));
func_ov001_02158fc4(*(void**)(data_ov001_02165880+0x24),vector,value);
return 1;
}

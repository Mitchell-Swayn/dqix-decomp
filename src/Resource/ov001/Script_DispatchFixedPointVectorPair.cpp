#include <globaldefs.h>
ARM
struct FloatParameterView;struct IntegerParameterView;
extern "C" void* memset(void*,int,unsigned);
extern "C" float ReadScriptParameterAsFloat(FloatParameterView*);
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
struct Vec3 {int x,y,z;};
extern "C" void func_ov001_02158f64(void*,Vec3,Vec3,int,int,bool);
extern "C" void* data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215D2CC; symbol: func_ov001_0215d2cc; size: 0x14C.
extern "C" int Script_DispatchFixedPointVectorPair(unsigned char* args,int count) {
 Vec3 first,second;
 memset(&first,0,12);
 memset(&second,0,12);
 first.x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)args));
 first.y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+8)));
 first.z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+16)));
 second.x=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+24)));
 second.y=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+32)));
 second.z=(int)(4096.0f*ReadScriptParameterAsFloat((FloatParameterView*)(args+40)));
 int value=ReadScriptParameterAsInteger((IntegerParameterView*)(args+48));
 bool flag=false;
 if(count>=8) flag=ReadScriptParameterAsInteger((IntegerParameterView*)(args+56))!=0;
 func_ov001_02158f64(data_ov001_02165880[9],first,second,value,1,flag);
 return 1;
}

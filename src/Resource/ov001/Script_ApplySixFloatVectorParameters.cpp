#include <globaldefs.h>
ARM
struct Vec {int x,y,z;};
extern "C" void* memset(void*,int,unsigned);
extern "C" float ReadScriptParameterAsFloat(void*);
extern "C" int ReadScriptParameterAsInteger(void*);
extern "C" void func_ov001_02158f64(void*,Vec,Vec,int,int,int);
extern "C" void func_ov001_02159168(void*,int,int,int,int,int,int);
extern "C" char data_ov001_02165880[];
// Original: arm9/ov001 @ 0x0215DD58; symbol: func_ov001_0215dd58; size: 0x180.
extern "C" int Script_ApplySixFloatVectorParameters(char* params,int count) {
 Vec a,b,unused;
 memset(&a,0,12);memset(&b,0,12);memset(&unused,0,12);
 b.x=(int)(4096.0f*ReadScriptParameterAsFloat(params));
 b.y=(int)(4096.0f*ReadScriptParameterAsFloat(params+8));
 b.z=(int)(4096.0f*ReadScriptParameterAsFloat(params+16));
 int x=(int)(4096.0f*ReadScriptParameterAsFloat(params+24));
 int y=(int)(4096.0f*ReadScriptParameterAsFloat(params+32));
 int z=(int)(4096.0f*ReadScriptParameterAsFloat(params+40));
 int option;
 int duration=ReadScriptParameterAsInteger(params+48);
 option=-1;
 if(count>=8)option=ReadScriptParameterAsInteger(params+56);
 func_ov001_02158f64(*(void**)(data_ov001_02165880+0x24),a,b,duration,1,0);
 func_ov001_02159168(*(void**)(data_ov001_02165880+0x24),x,y,z,duration,option,0);
 return 1;
}

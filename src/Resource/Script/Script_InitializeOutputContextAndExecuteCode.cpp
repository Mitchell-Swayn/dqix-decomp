#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct ScriptState {unsigned char a,b,c,pad;short d,e,f,g;unsigned short h,padE;unsigned* out;unsigned value;};extern "C" ScriptState data_02108cec;extern "C" Script::OpcodeLookupEntry data_020f0994[];
// Original: arm9/main @ 0x0206DA80; symbol: func_0206da80; size: 0xA0.
extern "C" int Script_InitializeOutputContextAndExecuteCode(unsigned* out,unsigned a,unsigned b,unsigned c,unsigned d,unsigned value,const void* code,unsigned length){Script script;if(data_02108cec.out){*out=0;data_02108cec.g=0;data_02108cec.f= -1;data_02108cec.d= -1;data_02108cec.e= -1;}*out=0;data_02108cec.c=a;data_02108cec.b=b;data_02108cec.a=c;data_02108cec.h=d;data_02108cec.out=out;data_02108cec.value=value;script.Initialize();script.SetOpcodeLookup(data_020f0994);script.Load(code,length);script.Execute();return 1;}

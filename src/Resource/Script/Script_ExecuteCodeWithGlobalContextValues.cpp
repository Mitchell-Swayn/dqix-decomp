#include <globaldefs.h>
#include <Resource/Script.h>
struct Context {unsigned char flag,pad;unsigned short value;unsigned zero;void* a;void* b;void* c;};extern "C" Context data_02108db0;extern "C" Script::OpcodeLookupEntry data_020f0cc8[];
// Original: arm9/main @ 0x020728AC; symbol: func_020728ac; size: 0x7C.
extern "C" void Script_ExecuteCodeWithGlobalContextValues(void* a,void* b,const void* code,unsigned length,void* c,unsigned short value,unsigned char flag) {data_02108db0.c=a;data_02108db0.b=b;data_02108db0.a=c;data_02108db0.value=value;data_02108db0.zero=0;data_02108db0.flag=flag;Script script;script.Initialize();script.SetOpcodeLookup(data_020f0cc8);script.Load(code,length);script.Execute();}

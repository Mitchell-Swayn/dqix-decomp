#include <globaldefs.h>
#include <Resource/Script.h>
struct Owner {char pad[0x480];void* a;unsigned b,c,d;};struct Result {char pad[12];unsigned value;char unknown[0x24];};extern "C" Script::OpcodeLookupEntry data_020f05bc[];extern "C" int FindGroupAndProcessHeadAfterClearingOutputCount(Owner*,int,Result*);extern "C" void func_0206f81c(Result*);
// Original: arm9/main @ 0x02064574; symbol: func_02064574; size: 0xA8.
extern "C" void Script_ExecuteCodeAndDispatchResult(Owner* self,void* a,const void* code,unsigned length,unsigned b,unsigned c,unsigned d) {if(a && code && length){self->a=a;self->b=b;self->c=c;self->d=d;Result result;Script script;script.Initialize();script.SetOpcodeLookup(data_020f05bc);script.Load(code,length);script.Execute();result.value=b;if(FindGroupAndProcessHeadAfterClearingOutputCount(self,20,&result))func_0206f81c(&result);}}

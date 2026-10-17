#include <globaldefs.h>
#include <Resource/Script.h>
struct State {unsigned b,a;};extern "C" State data_02108ee0;extern "C" Script::OpcodeLookupEntry data_020f0fb0[];extern "C" void Object_ResolveFourHalfwordIdsPerEntryToPointers(unsigned);
// Original: arm9/main @ 0x0207F524; symbol: func_0207f524; size: 0x70.
extern "C" ARM void Script_ExecuteCodeAndFinalizeGlobalContext(unsigned a,unsigned b,const void* code,unsigned size){if(b && code && size){data_02108ee0.b=b;data_02108ee0.a=a;Script script;script.Initialize();script.SetOpcodeLookup(data_020f0fb0);script.Load(code,size);script.Execute();Object_ResolveFourHalfwordIdsPerEntryToPointers(a);}}

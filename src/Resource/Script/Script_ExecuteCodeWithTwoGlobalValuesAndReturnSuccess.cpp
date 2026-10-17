#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned data_02108dd8;extern "C" unsigned data_020f0d2c;extern "C" Script::OpcodeLookupEntry data_020f0d30[];
// Original: arm9/main @ 0x0207416C; symbol: func_0207416c; size: 0x64.
extern "C" int Script_ExecuteCodeWithTwoGlobalValuesAndReturnSuccess(unsigned a,unsigned b,const void* code,unsigned size){data_02108dd8=a;data_020f0d2c=b;Script s;s.Initialize();s.SetOpcodeLookup(data_020f0d30);s.Load(code,size);s.Execute();return 1;}

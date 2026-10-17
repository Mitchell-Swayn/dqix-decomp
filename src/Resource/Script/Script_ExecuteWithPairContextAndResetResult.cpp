#include <globaldefs.h>
#include <Resource/Script.h>
ARM
struct State{unsigned short x,pad;unsigned a,b,c;};extern "C" State data_02108d98;extern "C" Script::OpcodeLookupEntry data_020f0c78[];
// Original: arm9/main @ 0x02071C00; symbol: func_02071c00; size: 0x64.
extern "C" void Script_ExecuteWithPairContextAndResetResult(unsigned a,unsigned b,const void* code,unsigned size){data_02108d98.c=a;data_02108d98.b=b;data_02108d98.a=0;data_02108d98.x=0;Script s;s.Initialize();s.SetOpcodeLookup(data_020f0c78);s.Load(code,size);s.Execute();}

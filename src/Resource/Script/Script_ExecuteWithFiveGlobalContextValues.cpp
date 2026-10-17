#pragma thumb off
#pragma optimization_level 4

#include <Resource/Script.h>
struct Context{unsigned char kind,pad;unsigned short id;int first,second,third;};
extern "C" {extern Context data_02109d94;extern Script::OpcodeLookupEntry data_020f18ec[];}
// Original: arm9/main @ 0x020A147C; symbol: func_020a147c; size: 0x80.
extern "C" void Script_ExecuteWithFiveGlobalContextValues(int first,int second,const void* code,unsigned length,int third,unsigned short id,unsigned char kind){if(second && code && length){data_02109d94.first=first;data_02109d94.second=second;data_02109d94.third=third;data_02109d94.id=id;data_02109d94.kind=kind;Script script;script.Initialize();script.SetOpcodeLookup(data_020f18ec);script.Load(code,length);script.Execute();}}

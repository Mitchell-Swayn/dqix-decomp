#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct State{unsigned char pad;unsigned char running;unsigned char flag;unsigned char pad3[3];unsigned short result;};extern "C" {extern State data_02109404;extern short data_020f13d8;extern Script::OpcodeLookupEntry data_020f13dc[];
// Original: arm9/main @ 0x020957F4; symbol: func_020957f4; size: 0x7C.
unsigned short Script_ExecuteCodeAndReturnGlobalResult(int unused,void* data,unsigned int size){data_02109404.result=0;data_02109404.running=1;data_02109404.flag=0;data_020f13d8=-1;Script script;script.Initialize();script.SetOpcodeLookup(data_020f13dc);script.Load(data,size);script.Execute();return data_02109404.result;}}

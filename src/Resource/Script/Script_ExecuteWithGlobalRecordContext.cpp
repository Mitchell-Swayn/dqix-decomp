#include <globaldefs.h>
#include <Resource/Script.h>
ARM
struct State{short x,pad;void* a;unsigned b;void* c;};extern "C" State data_0214e33c;extern "C" Script::OpcodeLookupEntry data_020f2308[];
// Original: arm9/main @ 0x020D7870; symbol: func_020d7870; size: 0x70.
extern "C" void Script_ExecuteWithGlobalRecordContext(unsigned char* p,unsigned b,const void* code,unsigned size,bool existing){data_0214e33c.c=p;data_0214e33c.b=b;if(!existing){data_0214e33c.a=p+4;data_0214e33c.x=*(short*)(p+20);}Script s;s.Initialize();s.SetOpcodeLookup(data_020f2308);s.Load(code,size);s.Execute();}

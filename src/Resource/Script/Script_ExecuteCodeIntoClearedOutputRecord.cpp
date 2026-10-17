#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned data_02108ee8[5];extern "C" Script::OpcodeLookupEntry data_020f0ff8[];
// Original: arm9/main @ 0x0208274C; symbol: func_0208274c; size: 0x78.
extern "C" int Script_ExecuteCodeIntoClearedOutputRecord(void* output,const void* code,unsigned size,unsigned mode){memset(output,0,84);data_02108ee8[4]=0;data_02108ee8[1]=0;data_02108ee8[2]=mode;data_02108ee8[3]=(unsigned)output;data_02108ee8[0]=0;Script s;s.Initialize();s.SetOpcodeLookup(data_020f0ff8);s.Load(code,size);s.Execute();return 0;}

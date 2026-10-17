#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
extern "C" {
extern void *data_021142c4;extern Script::OpcodeLookupEntry data_020f22d0[];
// Original: arm9/main @ 0x020D3C84; symbol: func_020d3c84; size: 0x6C.
void Script_ClearOwnerRecordAndExecuteCode(char *p,void *code,unsigned int len){Script script;memset(p,0,0xb4);*(int *)(p+0xb4)=0;data_021142c4=p;script.Initialize();script.SetOpcodeLookup(data_020f22d0);script.Load(code,len);script.Execute();}
}

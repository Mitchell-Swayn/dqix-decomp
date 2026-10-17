#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
extern "C" {
extern unsigned int data_02108fc8[];unsigned int *ReadGlobalValueAt020FB3F0();extern Script::OpcodeLookupEntry data_020f1248[];
// Original: arm9/main @ 0x0208DC00; symbol: func_0208dc00; size: 0x74.
unsigned int Script_ExecuteWithCurrentZoneAndReturnGlobalResult(void *code,unsigned int len,unsigned int arg){data_02108fc8[2]=arg;data_02108fc8[0]=0;data_02108fc8[1]=ReadGlobalValueAt020FB3F0()[2];Script script;script.Initialize();script.SetOpcodeLookup(data_020f1248);script.Load(code,len);script.Execute();return data_02108fc8[0];}
}

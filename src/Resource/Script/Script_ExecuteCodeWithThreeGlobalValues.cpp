#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
extern unsigned int data_02108ce0[];extern Script::OpcodeLookupEntry data_020f05f8[];
// Original: arm9/main @ 0x02064E2C; symbol: func_02064e2c; size: 0x5C.
bool Script_ExecuteCodeWithThreeGlobalValues(unsigned int a,unsigned int b,unsigned int c,void *code,unsigned int len){data_02108ce0[2]=a;data_02108ce0[1]=b;data_02108ce0[0]=c;Script script;script.Initialize();script.SetOpcodeLookup(data_020f05f8);script.Load(code,len);script.Execute();return true;}
}

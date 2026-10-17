#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
extern "C" {
extern unsigned int data_02108d04[];extern Script::OpcodeLookupEntry data_020f0a3c[];
// Original: arm9/main @ 0x0206EE80; symbol: func_0206ee80; size: 0x6C.
void Script_ExecuteWithFourGlobalParameters(unsigned int a,unsigned int b,void *code,unsigned int len,unsigned int c,short d){data_02108d04[3]=a;data_02108d04[2]=c;*(short *)data_02108d04=d;data_02108d04[1]=b;Script script;script.Initialize();script.SetOpcodeLookup(data_020f0a3c);script.Load(code,len);script.Execute();}
}

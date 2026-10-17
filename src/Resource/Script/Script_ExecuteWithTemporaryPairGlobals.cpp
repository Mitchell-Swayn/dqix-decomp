#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned data_020fdd30[2];extern "C" Script::OpcodeLookupEntry data_020ef6f4[];
// Original: arm9/main @ 0x02028048; symbol: func_02028048; size: 0x68.
extern "C" void Script_ExecuteWithTemporaryPairGlobals(unsigned a,unsigned b,const void* code,unsigned size){data_020fdd30[0]=a;data_020fdd30[1]=b;Script s;s.Initialize();s.SetOpcodeLookup(data_020ef6f4);s.Load(code,size);s.Execute();data_020fdd30[1]=0;data_020fdd30[0]=0;}

#include <globaldefs.h>
#include <Resource/Script.h>
ARM
extern "C" unsigned char data_02109404[];extern "C" Script::OpcodeLookupEntry data_020f1444[];
// Original: arm9/main @ 0x0209562C; symbol: func_0209562c; size: 0x8C.
extern "C" void Script_ExecuteCodeWithGlobalContextAndResetList(unsigned char* p,void* context,const void* code,unsigned size,unsigned short a,unsigned b,unsigned c){Script s;if(!context||!code||!size)return;*(unsigned short*)(data_02109404+8)=a;data_02109404[3]=b;data_02109404[4]=c;*(void**)(data_02109404+12)=context;*(unsigned*)(p+160)=0;data_02109404[0]=0;s.Initialize();s.SetOpcodeLookup(data_020f1444);s.Load(code,size);s.Execute();}

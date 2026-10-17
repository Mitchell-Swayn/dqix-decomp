#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct State {unsigned short pad,a,b,c;unsigned unused,result;char pad2[8];int mode;char pad3[4];void* output;};extern "C" State data_02108d70;extern "C" Script::OpcodeLookupEntry data_020f0b80[];
// Original: arm9/main @ 0x02071488; symbol: func_02071488; size: 0xEC.
extern "C" unsigned Script_ExecuteAndApplyModeDependentOutputCounts(void* code,unsigned size,int mode,char* out) {Script script;data_02108d70.output=out;data_02108d70.mode=mode;data_02108d70.result=0;data_02108d70.b=0;script.Initialize();script.SetOpcodeLookup(data_020f0b80);script.Load(code,size);script.Execute();out[7]=0;out[8]=0;if(mode>=21000 && mode<40000) {out[7]=1;short old=*(short*)(out+70);if(old>=0)*(short*)(out+70)=old+data_02108d70.a;}else if(mode>=40000) {out[8]=1;short old=*(short*)(out+70);if(old>=0)*(short*)(out+70)=old+data_02108d70.c;}return data_02108d70.result; }

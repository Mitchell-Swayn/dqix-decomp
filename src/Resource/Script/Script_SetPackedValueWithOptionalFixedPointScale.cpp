#include <globaldefs.h>
#include <Resource/Script.h>
struct Context {void* object;char pad[16];unsigned active;unsigned argument;};extern "C" Context* data_02109bb0;struct Value {short id,scale;};extern "C" void AppendHalfwordPairToResolvedRecord(void*,unsigned,Value*);
// Original: arm9/main @ 0x0209BA70; symbol: func_0209ba70; size: 0xAC.
extern "C" int Script_SetPackedValueWithOptionalFixedPointScale(Script::Parameter* params) {if(!data_02109bb0->active)return 1; {union {int raw;Value value;} local;local.raw=params[0].ToInt();if(params[1].type==2)local.value.scale=(short)(4096.0f*params[1].ToFloat());else if(params[1].type==1)local.value.scale=params[1].ToInt()<<12;if(local.value.scale==0)local.value.scale=0x1000;AppendHalfwordPairToResolvedRecord(data_02109bb0->object,data_02109bb0->argument,&local.value);}return 1;}

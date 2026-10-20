#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109bb0; symbol: data_02109bb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Context {void* object;char pad[16];unsigned active;unsigned argument;};extern "C" Context* ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage;struct Value {short id,scale;};extern "C" void Actor_AppendScaledChoiceValue(void*,unsigned,Value*);
// Original: arm9/main @ 0x0209BA70; symbol: func_0209ba70; size: 0xAC.
extern "C" int Script_SetPackedValueWithOptionalFixedPointScale(Script::Parameter* params) {if(!ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->active)return 1; {union {int raw;Value value;} local;local.raw=params[0].ToInt();if(params[1].type==2)local.value.scale=(short)(4096.0f*params[1].ToFloat());else if(params[1].type==1)local.value.scale=params[1].ToInt()<<12;if(local.value.scale==0)local.value.scale=0x1000;Actor_AppendScaledChoiceValue(ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->object,ScriptSetPresentGlobalOwnerValue_UnknownRoleZeroInitializedStorage->argument,&local.value);}return 1;}

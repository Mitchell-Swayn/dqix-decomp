#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109bac; symbol: data_02109bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Object{unsigned char pad[0x1c8];int key;int pad1cc;int index;};struct Context{Object* object;int pad;int enabled;};extern "C" {extern Context* MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;void Script_SetWeightedGroupCandidate(Object*,int,int,int*);unsigned char* Script_GetWeightedGroupByIndex(Object*,int);
// Original: arm9/main @ 0x0209AE10; symbol: func_0209ae10; size: 0x8C.
int MonsterGroupScript_AppendWeightedChoice(Script::Parameter* p){if(!MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->enabled)return 1;int key=MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->object->key;int index=MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->object->index;int value=p->ToInt();Script_SetWeightedGroupCandidate(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->object,key,index,&value);MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->object->index=index+1;unsigned char* record=Script_GetWeightedGroupByIndex(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage->object,key);if(record)record[3]++;return 1;}}

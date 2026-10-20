#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2108d70; symbol: data_02108d70.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct State{unsigned char active;unsigned char pad[15];int count;int pad14[2];int id;};extern "C" State ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x02071004; symbol: func_02071004; size: 0x40.
extern "C" int Script_IncrementMatchingOrActiveGlobalCount(Script::Parameter* p){int id=p->ToInt();if(ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.id==id||ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.active)ScriptAppendUniqueBoundedNamedEntry_UnknownRoleZeroInitializedStorage.count++;return 1;}

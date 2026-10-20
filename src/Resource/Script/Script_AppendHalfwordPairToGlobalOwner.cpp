#include <globaldefs.h>
#include <Resource/Script.h>
// Original data: arm9/main @ 0x2109ba8; symbol: data_02109ba8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage;extern "C" void SpellTable_AppendSpellMapping(void*,short*);
// Original: arm9/main @ 0x0209A77C; symbol: func_0209a77c; size: 0x40.
extern "C" ARM int Script_AppendHalfwordPairToGlobalOwner(Script::Parameter* p){short values[2];values[0]=p[0].ToInt();values[1]=p[1].ToInt();SpellTable_AppendSpellMapping(ScriptAllocateZeroedStateAndExecute_UnknownRoleZeroInitializedStorage,values);return 1;}

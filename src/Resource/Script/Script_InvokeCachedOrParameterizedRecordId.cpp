#include <globaldefs.h>
ARM
namespace Script { struct Parameter { char data[8]; int ToInt() const; }; }
// Original data: arm9/main @ 0x2108d98; symbol: data_02108d98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Selection { unsigned short id; unsigned short pad; void *cached; void *context; void *owner; }; extern "C" Selection ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage; extern "C" void ScriptRecordTable_AllocateInitializedRecords(void *,void *,unsigned short);
// Original: arm9/main @ 0x02071820; symbol: func_02071820; size: 0x54.
extern "C" int Script_InvokeCachedOrParameterizedRecordId(const Script::Parameter *args) { if(ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.cached&&ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.id) { ScriptRecordTable_AllocateInitializedRecords(ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.owner,ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.context,ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.id); } else { unsigned id=args->ToInt(); ScriptRecordTable_AllocateInitializedRecords(ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.owner,ScriptInvokeCachedOrParameterizedRecordId_UnknownRoleZeroInitializedStorage.context,id); } return 1; }

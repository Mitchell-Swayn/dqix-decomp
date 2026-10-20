#include <globaldefs.h>
#include <std_library_functions.h>
ARM
struct Entry { int value; char* string; };
struct Store { int count; unsigned int allocator; Entry** entries; };
// Original data: arm9/ov001 @ 0x2165800; symbol: data_ov001_02165800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" Store ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage;
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned int,unsigned int);
// Original: arm9/ov001 @ 0x021536FC; symbol: func_ov001_021536fc; size: 0xA4.
extern "C" int Script_AppendIntegerAndOwnedString(unsigned char* parameters) {
(*ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.entries)[ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.count].value=_ZNK6Script9Parameter5ToIntEv(parameters);
const char* string=_ZNK6Script9Parameter8ToStringEv(parameters+8);
if(!string)return 0;
(*ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.entries)[ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.count].string=_ZN13SafeAllocator8AllocateEj(ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.allocator,strlen(string)+1);
if(!(*ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.entries)[ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.count].string)return 0;
strcpy((*ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.entries)[ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.count].string,string);
++ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage.count;
return 1;
}

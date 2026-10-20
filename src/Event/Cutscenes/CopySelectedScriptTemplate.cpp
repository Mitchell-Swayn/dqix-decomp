#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658d8; symbol: data_ov001_021658d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char ScriptDisplayEventText_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x2165944; symbol: data_ov001_02165944.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char CopySelectedScriptTemplate_UnknownRoleZeroInitializedStorage[];
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void* Script_FindTextTableEntry(void*, int);
extern "C" void* memcpy(void*, const void*, unsigned);
// Original: arm9/ov001 @ 0x0215E444; symbol: func_ov001_0215e444; size: 0x70.
extern "C" int CopySelectedScriptTemplate(void* parameter) {
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x8c] = 0;
    int index = Script_ReadParameterAsInteger(parameter);
    if (index < 0) return 1;
    void* entry = Script_FindTextTableEntry(ScriptDisplayEventText_UnknownRoleZeroInitializedStorage, index);
    if (entry == 0) return 0;
    void* source = *(void**)((char*)entry + 4);
    if (source == 0) return 0;
    memcpy(CopySelectedScriptTemplate_UnknownRoleZeroInitializedStorage, source, 0x11);
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x9c] = 0;
    return 1;
}

#include <globaldefs.h>
ARM
struct Script { unsigned char storage[0x430]; };
struct ScriptOpcodeLookupEntry;
struct ScriptGlobals { short first; unsigned short pad; unsigned int second; unsigned int third; unsigned int fourth; };
// Original data: arm9/ov023 @ 0x21ffa34; symbol: data_ov023_021ffa34.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" volatile struct ScriptGlobals ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov023 @ 0x21fdc78; symbol: data_ov023_021fdc78.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6600000094111e0267000000ec111e020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char ScriptExecuteConfiguredBuffer_UnknownRoleProcedureReferenceRecords[];
extern "C" void _ZN6Script10InitializeEv(Script *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(Script *, ScriptOpcodeLookupEntry *);
extern "C" void _ZN6Script4LoadEPKvj(Script *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(Script *);
// Original: arm9/ov023 @ 0x021E133C; symbol: func_ov023_021e133c; size: 0x74.
extern "C" void Script_ExecuteConfiguredBuffer(unsigned int global0, unsigned int global1, const void *program, unsigned int length, unsigned int global4, short global0short) {
    if (program == 0 || length == 0) return;
    ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.fourth = global0;
    ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.third = global1;
    ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.second = global4;
    ScriptExecuteConfiguredBuffer_UnknownRoleZeroInitializedStorage.first = global0short;
    Script script;
    _ZN6Script10InitializeEv(&script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&script, (ScriptOpcodeLookupEntry *)ScriptExecuteConfiguredBuffer_UnknownRoleProcedureReferenceRecords);
    _ZN6Script4LoadEPKvj(&script, program, length);
    _ZN6Script7ExecuteEv(&script);
}

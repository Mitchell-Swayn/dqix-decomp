#include <globaldefs.h>
ARM
extern "C" void _ZN6Script10InitializeEv(void*);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*, void*);
extern "C" void _ZN6Script4LoadEPKvj(void*, const void*, unsigned);
extern "C" void _ZN6Script7ExecuteEv(void*);
// Original data: arm9/ov017 @ 0x21d83cc; symbol: data_ov017_021d83cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov017 @ 0x21d7900; symbol: data_ov017_021d7900.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000024ca1a02650000001cca1a02660000002cca1a020000000000000000.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned ScriptInitializeLoadAndExecute_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov017 @ 0x021ACC8C; symbol: func_ov017_021acc8c; size: 0x58.
extern "C" void Script_InitializeLoadAndExecute(void* context, const void* code, unsigned length, unsigned flags) {
    unsigned char script[0x430];
    ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage[0] = (unsigned)context;
    ScriptInitializeLoadAndExecute_UnknownRoleZeroInitializedStorage[1] = flags;
    _ZN6Script10InitializeEv(script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, ScriptInitializeLoadAndExecute_UnknownRoleProcedureReferenceRecords);
    _ZN6Script4LoadEPKvj(script, code, length);
    _ZN6Script7ExecuteEv(script);
}

#include <globaldefs.h>
ARM
struct Script { unsigned char storage[0x430]; };
struct ScriptOpcodeLookupEntry;
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" volatile unsigned int CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov000 @ 0x2183b5c; symbol: data_ov000_02183b5c.
// Combat resource script opcode dispatch. Registration at0216d1f4 calls Script::SetOpcodeLookup, which sorts eight-byte opcode/procedure records in place. Shared Script::OpcodeProc contract is int(Parameter*, int argumentCount). Opcode zero and null callback terminate the table.
// Initial values: hex 01000000f09b160202000000009d160203000000089d160204000000549e160205000000809e160206000000a49f16020700000018a0160208000000a4a11602 ...; full span in module reference.
// Observed span: 1120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CombatScriptCompileBufferToCommandGroups_CombatResourceScriptOpcodeDispatch[];
extern "C" void _ZN6Script10InitializeEv(Script *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(Script *, ScriptOpcodeLookupEntry *);
extern "C" void _ZN6Script4LoadEPKvj(Script *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(Script *);
// Original: arm9/ov000 @ 0x0216D1C4; symbol: func_ov000_0216d1c4; size: 0x70.
extern "C" void CombatScript_CompileBufferToCommandGroups(unsigned int globalValue, const void *program, unsigned int length, unsigned int *result) {
    Script script;
    CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2] = globalValue;
    CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[1] = 0;
    CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[0] = 0;
    _ZN6Script10InitializeEv(&script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(&script, (ScriptOpcodeLookupEntry *)CombatScriptCompileBufferToCommandGroups_CombatResourceScriptOpcodeDispatch);
    _ZN6Script4LoadEPKvj(&script, program, length);
    _ZN6Script7ExecuteEv(&script);
    *result = CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[0];
}

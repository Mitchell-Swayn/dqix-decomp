#include <globaldefs.h>
ARM
// Original data: arm9/ov003 @ 0x2180cb8; symbol: data_ov003_02180cb8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned char ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov003 @ 0x217ff40; symbol: data_ov003_0217ff40.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000e4e415026500000010e5150266000000fce515026700000028e615020000000000000000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" unsigned char ScriptExecuteBufferWithLookup_UnknownRoleProcedureReferenceRecords;
extern "C" void _ZN6Script10InitializeEv(void *);
extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void *, void *);
extern "C" void _ZN6Script4LoadEPKvj(void *, const void *, unsigned int);
extern "C" void _ZN6Script7ExecuteEv(void *);
// Original: arm9/ov003 @ 0x0215E6F8; symbol: func_ov003_0215e6f8; size: 0x58.
extern "C" void Script_ExecuteBufferWithLookup(void *globalA, void *globalB, const void *buffer, unsigned int size) {
    unsigned char script[0x430];
    *(void **)(&ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage + 4) = globalA;
    *(void **)&ScriptExecuteBufferWithLookup_UnknownRoleZeroInitializedStorage = globalB;
    _ZN6Script10InitializeEv(script);
    _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script, &ScriptExecuteBufferWithLookup_UnknownRoleProcedureReferenceRecords);
    _ZN6Script4LoadEPKvj(script, buffer, size);
    _ZN6Script7ExecuteEv(script);
}

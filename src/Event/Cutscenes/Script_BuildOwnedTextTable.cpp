#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov001 @ 0x2164b80; symbol: data_ov001_02164b80.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000e03615020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x2164b90; symbol: data_ov001_02164b90.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000fc3615020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
// Original data: arm9/ov001 @ 0x2165800; symbol: data_ov001_02165800.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[];extern "C" char ScriptBuildOwnedTextTable_UnknownRoleProcedureReferenceRecords[],ScriptBuildOwnedTextTable_UnknownRoleProcedureReferenceRecords_Variant2[];extern "C" void _ZN6Script10InitializeEv(void*);extern "C" void _ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(void*,void*);extern "C" void _ZN6Script4LoadEPKvj(void*,const void*,unsigned);extern "C" void _ZN6Script7ExecuteEv(void*);extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);
// Original: arm9/ov001 @ 0x021537B0; symbol: Script_BuildEightByteOutputRecordsInTwoPasses; size: 0xD4.
extern "C" void Script_BuildOwnedTextTable(unsigned* output,void* allocator,const void* code,unsigned length){char script[0x430];output[0]=0;output[1]=0;ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[0]=0;ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[1]=(unsigned)allocator;ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[2]=(unsigned)output;_ZN6Script10InitializeEv(script);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,ScriptBuildOwnedTextTable_UnknownRoleProcedureReferenceRecords);_ZN6Script4LoadEPKvj(script,code,length);_ZN6Script7ExecuteEv(script);output[1]=ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[0];ScriptBuildOwnedTextTable_UnknownRoleZeroInitializedStorage[0]=0;output[0]=(unsigned)_ZN13SafeAllocator8AllocateEj(allocator,output[1]*8);if(!output[0]){output[1]=0;return;}_ZN6Script10InitializeEv(script);_ZN6Script15SetOpcodeLookupEPNS_17OpcodeLookupEntryE(script,ScriptBuildOwnedTextTable_UnknownRoleProcedureReferenceRecords_Variant2);_ZN6Script4LoadEPKvj(script,code,length);_ZN6Script7ExecuteEv(script);}

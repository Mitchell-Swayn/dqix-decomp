#include <globaldefs.h>
ARM
#include <Resource/Script.h>
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
// Original data: arm9/ov016 @ 0x219d1bc; symbol: data_ov016_0219d1bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" char *ScriptBuildStringOptions_UnknownRoleZeroInitializedStorage;
extern "C" char Script_LoadFileAndExecuteWithOwner_PathDataMovieMovielistBin[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/ov016 @ 0x219d044; symbol: data_ov016_0219d044.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 6400000060de18020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" Script::OpcodeLookupEntry ScriptLoadFileAndExecuteWithOwner_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov016 @ 0x0218E098; symbol: func_ov016_0218e098; size: 0x8C.
extern "C" void Script_LoadFileAndExecuteWithOwner(char *self, void *context) {
    *(void **)(self + 8) = context;
    ScriptBuildStringOptions_UnknownRoleZeroInitializedStorage = self;
    _ZN16BackgroundLoader13AddLockGlobalEv();
    unsigned length;
    void *code = _Z18LoadFileIntoMemoryPKcPvPj(Script_LoadFileAndExecuteWithOwner_PathDataMovieMovielistBin, Main_UnknownRoleZeroInitializedStorage_Variant6, &length);
    if (code) {
        Script script;
        script.Initialize();
        script.SetOpcodeLookup(ScriptLoadFileAndExecuteWithOwner_UnknownRoleProcedureReferenceRecords);
        script.Load(code, length);
        script.Execute();
    }
    _ZN16BackgroundLoader16RemoveLockGlobalEv();
    *(void **)(self + 8) = 0;
}

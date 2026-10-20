#include <globaldefs.h>
#include <Resource/Script.h>
#include <Filesystem/BackgroundLoader.h>
#include <Filesystem/FileIO.h>
#include <std_library_functions.h>
extern "C" {
    extern char CharacterPalette_LoadConfigurationScript_PathDataCharaPaletteBin[];
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6[];
// Original data: arm9/main @ 0x20f1574; symbol: data_020f1574.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 64000000c49a090265000000209b0902660000007c9b090267000000d89b090268000000349c090269000000909c09020000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern Script::OpcodeLookupEntry CharacterPaletteLoadConfigurationScript_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/main @ 0x02099CB8; symbol: func_02099cb8; size: 0x7C.
    void CharacterPalette_LoadConfigurationScript(void *p){
        unsigned int len;
        Script script;
        memset(p,0,300);
        BackgroundLoader::AddLockGlobal();
        void *code=LoadFileIntoMemory(CharacterPalette_LoadConfigurationScript_PathDataCharaPaletteBin,Main_UnknownRoleZeroInitializedStorage_Variant6,&len);
        if(code){
            script.Initialize();
            script.SetOpcodeLookup(CharacterPaletteLoadConfigurationScript_UnknownRoleProcedureReferenceRecords);
            script.Load(code,len);
            script.Execute();
        }BackgroundLoader::RemoveLockGlobal();
    }
}

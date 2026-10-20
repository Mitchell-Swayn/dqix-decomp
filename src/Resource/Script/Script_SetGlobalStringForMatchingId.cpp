#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x20fdc4c; symbol: data_020fdc4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned int PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[];
    unsigned short *Zone3D_GetMainInstance();
// Original: arm9/main @ 0x0201F950; symbol: func_0201f950; size: 0x50.
    bool Script_SetGlobalStringForMatchingId(Script::Parameter *p){
        if(PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[1])return true;
        int value=p[0].ToInt();
        if(value==*Zone3D_GetMainInstance())PartyStatusRefreshMemberRatioPaletteColors_UnknownRoleZeroInitializedStorage[1]=(unsigned int)p[1].ToString();
        return true;
    }
}

#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2109928; symbol: data_02109928.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern short ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage[10][2];
// Original: arm9/main @ 0x02099AC4; symbol: func_02099ac4; size: 0x5C.
    bool Script_ReadTenPairsIntoGlobalTable(Script::Parameter *p){
        for(int i=0;i<10;i++)for(int j=0;j<2;j++){
            ScriptReadTenPairsIntoGlobalTable_UnknownRoleZeroInitializedStorage[i][j]=p->ToInt();
            p++;
        }return true;
    }
}

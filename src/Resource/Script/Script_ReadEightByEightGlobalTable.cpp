#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x21099b0; symbol: data_021099b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern short ScriptReadEightByEightGlobalTable_UnknownRoleZeroInitializedStorage[8][8];
// Original: arm9/main @ 0x02099BD8; symbol: func_02099bd8; size: 0x5C.
    bool Script_ReadEightByEightGlobalTable(Script::Parameter *p){
        for(int i=0;i<8;i++)for(int j=0;j<8;j++){
            ScriptReadEightByEightGlobalTable_UnknownRoleZeroInitializedStorage[i][j]=p->ToInt();
            p++;
        }return true;
    }
}

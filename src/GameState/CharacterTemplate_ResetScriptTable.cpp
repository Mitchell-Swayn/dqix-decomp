#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    void CharacterTemplate_ClearScriptTable(void *);
// Original: arm9/main @ 0x02089DDC; symbol: func_02089ddc; size: 0xC.
    void CharacterTemplate_ResetScriptTable(void *p){
        CharacterTemplate_ClearScriptTable(p);
    }
}

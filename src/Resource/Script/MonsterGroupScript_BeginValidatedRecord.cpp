#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" {
// Original data: arm9/main @ 0x2109bac; symbol: data_02109bac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char *MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;
    void *Actor_FindChoiceById(void *,int);
// Original: arm9/main @ 0x0209AE9C; symbol: func_0209ae9c; size: 0x98.
    bool MonsterGroupScript_BeginValidatedRecord(Script::Parameter *p){
        *(int *)(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+8)=0;
        int id=p->ToInt();
        if(!Actor_FindChoiceById(*(void **)(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+4),id))return true;
        unsigned char *owner=*(unsigned char **)MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage;
        int count=*(int *)(owner+0x1c8)+1;
        *(int *)(owner+0x1c8)=count;
        *(int *)(*(unsigned char **)MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+0x1cc)=0;
        *(int *)(*(unsigned char **)MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+0x1d0)=0;
        *(short *)(*(unsigned char **)MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+count*76)=id;
        *(int *)(MonsterGroupScriptAppendWeightedChoice_UnknownRoleZeroInitializedStorage+8)=1;
        return true;
    }
}

#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    int BestiaryInfo_GetMonsterId(void *);
    void *BestiaryInfo_FindEntryByKey(void *,int,int (*)(void *));
// Original: arm9/main @ 0x02097224; symbol: func_02097224; size: 0x14.
    void *BestiaryInfo_FindMonsterRecord(void *p,int id){
        return BestiaryInfo_FindEntryByKey(p,id,BestiaryInfo_GetMonsterId);
    }
}

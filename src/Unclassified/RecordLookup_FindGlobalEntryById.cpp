#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    extern unsigned char data_021536ac[];
    void *ResolveIndexedRecordAndReturnSecondWord(void *,int);
// Original: arm9/main @ 0x020E51E4; symbol: func_020e51e4; size: 0x18.
    void *RecordLookup_FindGlobalEntryById(int id){
        return ResolveIndexedRecordAndReturnSecondWord(data_021536ac,id);
    }
}

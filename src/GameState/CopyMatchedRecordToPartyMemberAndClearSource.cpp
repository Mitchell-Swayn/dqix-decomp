#pragma optimization_level 4
#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
extern "C" {
    unsigned char *Object_FindKeyInThreeTwentyByteRecords(void *,int);
    unsigned char *ReadWordFieldAtOffset150(void *);
// Original: arm9/main @ 0x020875C4; symbol: func_020875c4; size: 0x64.
    void CopyMatchedRecordToPartyMemberAndClearSource(void *p,int key,int id){
        unsigned char *q=Object_FindKeyInThreeTwentyByteRecords(p,key);
        if(!q)return;
        GameObject *obj=GameState::GetInstance()->GetPartyMemberByIndex(id);
        if(!obj)return;
        unsigned char *data=ReadWordFieldAtOffset150(obj);
        if(!data)return;
        memcpy(data+0x454,q,16);
        memset(q,0,20);
        ((signed char *)q)[16]=-1;
    }
}

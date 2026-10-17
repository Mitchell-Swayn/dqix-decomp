#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" {
    void *Object_GetGlobalConnectionState();
    bool TestActiveWordAndGlobalStateNonzero(void *);
    bool RecordArray_FindFourEntryTagAndOptionalKeyMatch(void *,int,int);
    unsigned char *ResetAndReturnFirstInactiveOfFourEntries(void *);
    void QueueTaggedRecordOperationMessage34(int,unsigned char,int);
// Original: arm9/main @ 0x020E392C; symbol: func_020e392c; size: 0x68.
    void RecordArray_InsertMissingTagAndNotifyOverlay(void *p,int id,int value){
        if(TestActiveWordAndGlobalStateNonzero(Object_GetGlobalConnectionState()))return;
        if(RecordArray_FindFourEntryTagAndOptionalKeyMatch(p,id,value))return;
        unsigned char *q=ResetAndReturnFirstInactiveOfFourEntries(p);
        if(!q)return;
        GameState::GetInstance();
        q[4]=id;
        *(int *)q=value;
        QueueTaggedRecordOperationMessage34(3,id,value);
    }
}

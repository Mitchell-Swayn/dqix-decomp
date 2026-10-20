#include <globaldefs.h>
extern "C" {
    unsigned int SoundCommand_IsTransportAvailable();
    unsigned int SoundCommand_TakeFreeCommand();
    int SoundCommand_CountFreeRecords();
    int SoundCommand_ReclaimCompletedBatch(int);
    void SoundCommand_FlushPendingBatch(int);
    void IPC_SendARM7CommandSevenUntilAccepted();
// Original: arm9/main @ 0x020D2404; symbol: func_020d2404; size: 0x88.
    unsigned int SoundCommand_AllocateRecordWithOptionalWait(int flags){
        if(!SoundCommand_IsTransportAvailable())return 0;
        unsigned int result=SoundCommand_TakeFreeCommand();
        if(result)return result;
        if(!(flags&1))return 0;
        if(SoundCommand_CountFreeRecords()>0){
            while(SoundCommand_ReclaimCompletedBatch(0)){
            }result=SoundCommand_TakeFreeCommand();
            if(result)return result;
        }else SoundCommand_FlushPendingBatch(1);
        IPC_SendARM7CommandSevenUntilAccepted();
        do{
            SoundCommand_ReclaimCompletedBatch(1);
            result=SoundCommand_TakeFreeCommand();
        }while(!result);
        return result;
    }
}

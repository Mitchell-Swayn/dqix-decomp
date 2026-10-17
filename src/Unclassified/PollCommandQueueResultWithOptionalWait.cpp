#include <globaldefs.h>
extern "C" {
    unsigned int ProbeHardwareRegisterUnderIRQProtection();
    unsigned int SoundCommand_PopPendingRecordAtomically();
    int ComputeRemainingSpaceIn256EntryCommandQueue();
    int func_020d22f4(int);
    void func_020d24c4(int);
    void IPC_SendARM7CommandSevenUntilAccepted();
// Original: arm9/main @ 0x020D2404; symbol: func_020d2404; size: 0x88.
    unsigned int PollCommandQueueResultWithOptionalWait(int flags){
        if(!ProbeHardwareRegisterUnderIRQProtection())return 0;
        unsigned int result=SoundCommand_PopPendingRecordAtomically();
        if(result)return result;
        if(!(flags&1))return 0;
        if(ComputeRemainingSpaceIn256EntryCommandQueue()>0){
            while(func_020d22f4(0)){
            }result=SoundCommand_PopPendingRecordAtomically();
            if(result)return result;
        }else func_020d24c4(1);
        IPC_SendARM7CommandSevenUntilAccepted();
        do{
            func_020d22f4(1);
            result=SoundCommand_PopPendingRecordAtomically();
        }while(!result);
        return result;
    }
}

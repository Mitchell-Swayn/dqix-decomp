#include <globaldefs.h>
extern "C" {
    void SoundCommand_SubmitOpcodeTwelve(int,int,unsigned int,int);
    void PowerManagement_PrependSleepCallback(void *);
    void LinkedList_AppendEntryToGlobalPendingList(void *);
    struct SignedFlag{
        unsigned int low:1;
        signed int flag:1;
        unsigned int high:30;
    };
// Original: arm9/main @ 0x020BCB70; symbol: func_020bcb70; size: 0x54.
    void NNS_SndStrmStart(unsigned char *p){
        SoundCommand_SubmitOpcodeTwelve(*(int *)(p+68),0,1U<<*(int *)(p+64),0);
        if(((SignedFlag *)(p+36))->flag)return;
        PowerManagement_PrependSleepCallback(p+8);
        LinkedList_AppendEntryToGlobalPendingList(p+20);
        *(int *)(p+36)|=2;
    }
}

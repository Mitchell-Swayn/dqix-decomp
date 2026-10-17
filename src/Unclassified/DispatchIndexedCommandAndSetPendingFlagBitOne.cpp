#include <globaldefs.h>
extern "C" {
    void SubmitOperationCodeTwelve(int,int,unsigned int,int);
    void InvokeGlobalHeadListHandler(void *);
    void LinkedList_AppendEntryToGlobalPendingList(void *);
    struct SignedFlag{
        unsigned int low:1;
        signed int flag:1;
        unsigned int high:30;
    };
// Original: arm9/main @ 0x020BCB70; symbol: func_020bcb70; size: 0x54.
    void DispatchIndexedCommandAndSetPendingFlagBitOne(unsigned char *p){
        SubmitOperationCodeTwelve(*(int *)(p+68),0,1U<<*(int *)(p+64),0);
        if(((SignedFlag *)(p+36))->flag)return;
        InvokeGlobalHeadListHandler(p+8);
        LinkedList_AppendEntryToGlobalPendingList(p+20);
        *(int *)(p+36)|=2;
    }
}

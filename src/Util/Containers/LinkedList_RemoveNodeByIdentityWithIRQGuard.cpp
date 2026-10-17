#include <globaldefs.h>
#include <System/Interrupts.h>
extern "C" {
    struct Node{
        int a,b;
        Node *next;
    };
// Original: arm9/main @ 0x020CEEB4; symbol: func_020ceeb4; size: 0x58.
    void LinkedList_RemoveNodeByIdentityWithIRQGuard(Node **list,Node *remove){
        if(!list)return;
        int old=DisableIRQInterrupts();
        Node *p=*list;
        Node *previous=p;
        if(p)do{
            if(p==remove){
                Node *next=p->next;
                if(p==previous)*list=next;
                else previous->next=next;
                break;
            }previous=p;
            p=p->next;
        }while(p);
        SetIRQInterruptState(old);
    }
}

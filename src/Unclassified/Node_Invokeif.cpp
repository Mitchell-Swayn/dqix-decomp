#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
    struct Node{
        void (*callback)(void *);
        void *arg;
        Node *next;
    };
// Original: arm9/main @ 0x020CEF0C; symbol: func_020cef0c; size: 0x28.
    void Node_Invokeif(Node *p){
        if(!p)return;
        do{
            p->callback(p->arg);
            p=p->next;
        }while(p);
    }
}

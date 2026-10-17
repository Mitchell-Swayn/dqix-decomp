#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <System/Interrupts.h>
extern "C" {
    void AppendAllocatorNodeToGlobalListWithIRQDisabled(void *);
// Original: arm9/main @ 0x020BF358; symbol: func_020bf358; size: 0x70.
    void RemoveMatchingAllocatorNodesWithIRQDisabled(SignedAllocatorList *list,unsigned int key){
        int old=DisableIRQInterrupts();
        SignedAllocatorHeader *p=list->ElementAfter(0);
        if(p)do{
            SignedAllocatorHeader *next=list->ElementAfter(p);
            if(*(unsigned int *)((unsigned char *)p+8)==key){
                list->Remove(p);
                AppendAllocatorNodeToGlobalListWithIRQDisabled(p);
            }p=next;
        }while(p);
        SetIRQInterruptState(old);
    }
}

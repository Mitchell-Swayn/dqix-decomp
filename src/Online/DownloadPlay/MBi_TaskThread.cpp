#include <globaldefs.h>
#include <System/ProcessorContext.h>
#include <System/Interrupts.h>
ARM
struct Task { Task *next; unsigned flags; void (*run)(Task*); void (*complete)(Task*); unsigned char pad[16]; };
struct TaskThread { unsigned char context[0xc0]; Task * volatile head; Task endTask; };
// Original: arm9/ov027 @ 0x021DD218; symbol: func_ov027_021dd218; size: 0x118.
// Runs queued tasks at their encoded priorities and invokes completion callbacks under the IRQ mask.
extern "C" void MBi_TaskThread(TaskThread *thread)
{
    Task *task;
    int completionIrq;
    int irq;
    void (*completion)(Task*);
    for(;;) {
        irq=DisableIRQInterrupts();
        while(!thread->head) {
            ChangeContextPriority((ProcessorContext*)thread,0);
            BlockCurrentContext(0);
        }
        task=thread->head;
        thread->head=thread->head->next;
        ChangeContextPriority((ProcessorContext*)thread,task->flags>>1);
        SetIRQInterruptState(irq);
        if(task->run)task->run(task);
        completionIrq=DisableIRQInterrupts();
        completion=task->complete;
        unsigned priority=GetContextPriority((ProcessorContext*)thread);
        unsigned nextPriority;
        if(!thread->head)nextPriority=0;
        else nextPriority=priority<thread->head->flags>>1 ? thread->head->flags>>1 : priority;
        if(nextPriority!=priority)ChangeContextPriority((ProcessorContext*)thread,nextPriority);
        task->next=0;
        task->flags&=~1;
        if(completion)completion(task);
        if(task==&thread->endTask)break;
        SetIRQInterruptState(completionIrq);
    }
    ContextExecutionReturnProc();
}

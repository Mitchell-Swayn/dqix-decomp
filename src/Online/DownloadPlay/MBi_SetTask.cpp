#include <globaldefs.h>
#include <System/ProcessorContext.h>
#include <System/Interrupts.h>
ARM
struct QueueTask { QueueTask *next; unsigned busy:1; unsigned priority:31; void (*run)(QueueTask*); void (*complete)(QueueTask*); unsigned char pad[16]; };
struct QueueThread { unsigned char context[0xc0]; QueueTask * volatile head; QueueTask endTask; };
// Original data: arm9/ov027 @ 0x21e3420; symbol: data_ov027_021e3420.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" QueueThread *MBiSetTask_UnknownRoleZeroInitializedStorage;
extern "C" int MBi_IsTaskAvailable();
// Original: arm9/ov027 @ 0x021DD3F8; symbol: func_ov027_021dd3f8; size: 0x164.
// Queues a task by priority, with relative-priority requests and a terminal-task append path.
extern "C" void MBi_SetTask(QueueTask *task,void (*run)(QueueTask*),void (*complete)(QueueTask*),unsigned priority)
{
    QueueThread *thread=MBiSetTask_UnknownRoleZeroInitializedStorage;
    if(!MBi_IsTaskAvailable())return;
    if(task->busy)return;
    if(priority>31) {
        unsigned current=GetContextPriority((ProcessorContext*)thread);
        if(priority==32) priority=current?current-1:0;
        else if(priority==33) priority=current<31?current+1:31;
        else if(priority==34) priority=current;
        else priority=31;
    }
    int irq=DisableIRQInterrupts();
    task->busy=1;
    task->priority=priority;
    task->run=run;
    task->complete=complete;
    if(!thread->head) {
        if(task==&thread->endTask)MBiSetTask_UnknownRoleZeroInitializedStorage=0;
        thread->head=task;
        MarkContextReadyAndSwitch((ProcessorContext*)thread);
    } else {
        QueueTask *entry=thread->head;
        if(task==&thread->endTask) {
            while(entry->next)entry=entry->next;
            entry->next=task;
            MBiSetTask_UnknownRoleZeroInitializedStorage=0;
        } else if(priority<entry->priority) {
            thread->head=task;
            task->next=entry;
        } else {
            QueueTask *next;
            while((next=entry->next)!=0 && priority>=next->priority)entry=next;
            task->next=next;
            entry->next=task;
        }
    }
    SetIRQInterruptState(irq);
}

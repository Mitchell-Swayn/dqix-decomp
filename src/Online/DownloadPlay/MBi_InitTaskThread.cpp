#include <globaldefs.h>
#include <System/ProcessorContext.h>
#include <System/Interrupts.h>

struct Task { Task* next; unsigned flags; void (*run)(Task*); void (*complete)(Task*); unsigned char pad[16]; };
struct TaskThread { unsigned char context[0xc0]; Task* volatile head; Task endTask; };
struct QueueThread;
extern "C" QueueThread* MBiSetTask_UnknownRoleZeroInitializedStorage;
extern "C" void ClearTaskInfo(void*);
extern "C" void MBi_TaskThread(TaskThread*);
#pragma force_active on
// Original: arm9/ov027 @ 0x021DD330; symbol: func_ov027_021dd330; size: 0x80.
// Initializes the shared task queue, assigns the remaining aligned storage as its thread stack, and starts the task context.
extern "C" void MBi_InitTaskThread(TaskThread* thread, unsigned int size)
{
    int irq = DisableIRQInterrupts();
    if (!MBiSetTask_UnknownRoleZeroInitializedStorage)
    {
        MBiSetTask_UnknownRoleZeroInitializedStorage = (QueueThread*)thread;
        ClearTaskInfo(&thread->endTask);
        thread->head = 0;
        unsigned int stackSize = (size - 0xe4) & ~3;
        PopulateProcessorContext((ProcessorContext*)thread, (unsigned int)MBi_TaskThread, (unsigned int)thread,
            (unsigned int)((char*)thread + 0xe4 + stackSize), stackSize, 0);
        MarkContextReadyAndSwitch((ProcessorContext*)thread);
    }
    SetIRQInterruptState(irq);
}

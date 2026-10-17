typedef struct TaskState TaskState;
/* Only queue fields used by this entry point are named; intervening state remains unknown. */
struct TaskState { unsigned char reserved[0x200]; unsigned char scheduler[0x108]; void *messageQueue; };
extern TaskState *ARM7_TaskState;
extern void ARM7_AppendScheduledTask(void *scheduler, void *message);
extern void ARM7_ScheduleTask(int priority, int slot);
void ARM7_ConsumeTaskMessage(void **message);
// Original: arm7/wram @ 0x037F86FC; symbol: ARM7_WaitTaskMessage.
void ARM7_WaitTaskMessage(void)
{
    void *message;
    extern int ARM7_ReceiveMessage(void *queue, void **message, int flags);
    ARM7_ReceiveMessage(ARM7_TaskState->messageQueue, &message, 1);
    ARM7_ConsumeTaskMessage(&message);
    ARM7_ScheduleTask(3, 12);
}

// Original: arm7/wram @ 0x037F8738; symbol: ARM7_ConsumeTaskMessage.
void ARM7_ConsumeTaskMessage(void **message)
{
    void *task = *message;
    if (task != 0) {
        ARM7_AppendScheduledTask(ARM7_TaskState->scheduler, task);
        ARM7_ScheduleTask(2, 11);
    }
}

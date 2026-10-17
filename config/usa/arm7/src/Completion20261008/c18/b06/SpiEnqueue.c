/* Queue an SPI service task with up to four word arguments. The variadic
 * cursor follows the matching ARM ABI's four-byte aligned argument slots. */
#pragma dont_inline on
#include "../../../SpiService.h"
typedef char *ArgumentCursor;
#define ARGUMENT_START(cursor,last) ((cursor)=(char*)(((unsigned int)&(last)&~3u)+4))
#define ARGUMENT_WORD(cursor) (*(unsigned int*)((cursor+=4)-4))
/* The following symbols are views into the already inventoried service state.
 * Volatile reads retain the original index reload after each task write. */
extern SpiTask ARM7_SpiTaskTypes[16];
typedef struct {unsigned int value,padding[5];} CommandSlot;
extern CommandSlot ARM7_SpiTaskCommands[16];
typedef struct {unsigned char prefix[0x314];unsigned int argument;} SpiArgumentView;
extern unsigned char ARM7_SpiArgumentBase[];
#define NEXT_TASK (*(volatile unsigned int*)&ARM7_SpiServiceState.body.nextTask)
extern int ARM7_DisableIRQInterrupts(void);
extern int ARM7_SetIRQInterruptState(int);
extern int ARM7_SendMessage(MessageQueue*,void*,int);
// Original: arm7/wram @ 0x03804D90; symbol: ARM7_EnqueueSpiTask.
int ARM7_EnqueueSpiTask(unsigned int type,unsigned int command,unsigned short count,...)
{
 ArgumentCursor arguments;
 int state,index;
 register int argumentCount;
 unsigned int task;
 if(count>4)return 0;
 state=ARM7_DisableIRQInterrupts();
 ARM7_SpiTaskTypes[NEXT_TASK].type=type;
 ARM7_SpiTaskCommands[NEXT_TASK].value=command;
 ARGUMENT_START(arguments,count);
 argumentCount=count;
 for(index=0;index<argumentCount;index++)
  ((SpiArgumentView*)(ARM7_SpiArgumentBase+NEXT_TASK*24+index*4))->argument=ARGUMENT_WORD(arguments);
 task=NEXT_TASK;
 NEXT_TASK=(task+1)&15;
 ARM7_SetIRQInterruptState(state);
 return ARM7_SendMessage(&ARM7_SpiTaskQueue,&ARM7_SpiTaskTypes[task],0);
}

/* Receive SPI tasks and dispatch the four observed handler types. */
#pragma dont_inline on
#include "SpiService.h"
extern int ARM7_ReceiveMessage(MessageQueue*,void**,int);
extern void ARM7_SpiTaskHandler0(SpiTask*);
extern void ARM7_SpiTaskHandler1(SpiTask*);
extern void ARM7_SpiTaskHandler2(SpiTask*);
extern void ARM7_ExecutePowerTask(SpiTask*);
void ARM7_SpiWorkerMain(void)
{
 SpiTask *task;
 for(;;) {
  ARM7_ReceiveMessage(&ARM7_SpiTaskQueue,(void**)&task,1);
  switch(task->type) {
  case 0:ARM7_SpiTaskHandler0(task);break;
  case 2:ARM7_SpiTaskHandler2(task);break;
  case 3:ARM7_ExecutePowerTask(task);break;
  case 1:ARM7_SpiTaskHandler1(task);break;
  }
 }
}

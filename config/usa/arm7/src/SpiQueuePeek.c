/* Return the result of nonblocking SPI task queue inspection. */
#pragma dont_inline on
#include "SpiService.h"
extern int ARM7_PeekMessage(MessageQueue*,void**,int);
int ARM7_HasQueuedSpiTask(void)
{
 void *task;
 return ARM7_PeekMessage(&ARM7_SpiTaskQueue,&task,0);
}
